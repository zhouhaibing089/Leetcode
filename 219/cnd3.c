#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* hash table */
typedef struct table table;
/* item entry */
typedef struct entry entry;

struct entry {
  /* the value at this nodee */
  int val;
  /* is this node alive */
  bool alive;
};

struct table {
  /* buckets */
  entry** buckets;
  /* the prime */
  int prime;
};

/* create table */
table* table_init(int s) {
  // /* primary table */
  // static int pt[10] = {
  //   2, 3, 5, 7, 11, 13, 17, 19, 23, 29
  // };
  table* t = (table*)malloc(sizeof(table));
  t->buckets = NULL;
  // for (int i = 0; i < 10; ++i) {
  //   if (s <= pt[i]) {
  //     t->prime = pt[i];
  //     t->buckets = (entry**)malloc(sizeof(entry*) * pt[i]);
  //     break;
  //   }
  // }
  // if (t->buckets == NULL) {
  t->prime = s;
  t->buckets = (entry**)malloc(sizeof(entry*) * s);
  // }
  for (int i = 0; i < t->prime; ++i) {
    entry* e = (entry*)malloc(sizeof(entry));
    e->alive = false;
    t->buckets[i] = e;
  }
  return t;
}

/* insert */
void table_insert(table* t, int val) {
  int index = val % t->prime;
  if (index < 0) {
    index = 0 - index;
  }
  entry* e = t->buckets[index];
  while (e->alive) {
    index = (index + 1) % t->prime;
    e = t->buckets[index];
  }
  /* find the available bucket */
  printf("Insert %d at index %d\n", val, index);
  e->alive = true;
  e->val = val;
}

/* remove */
void table_remove(table* t, int val) {
  int index = val % t->prime;
  if (index < 0) {
    index = 0 - index;
  }
  entry* e = t->buckets[index];
  int pos = -1;
  while (e->alive) {
    if (e->val == val) {
      pos = index;
    }
    index = (index + 1) % t->prime;
    e = t->buckets[index];
  }
  if (pos > -1) {
    printf("Remove %d at index %d\n", val, pos);
    t->buckets[pos]->alive = false;
  }
}

/* find */
bool table_find(table* t, int val) {
  int index = val % t->prime;
  if (index < 0) {
    index = 0 - index;
  }
  entry* e = t->buckets[index];
  while (e->alive) {
    if (e->val == val) {
      printf("Found %d at index %d\n", val, index);
      return true;
    }
    index = (index + 1) % t->prime;
    e = t->buckets[index];
  }
  return false;
}

/* free the allocated memory */
void table_free(table* t) {
  for (int i = 0; i < t->prime; ++i) {
    free(t->buckets[i]);
  }
  free(t->buckets);
  free(t);
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  table* t = table_init(k + 2);
  int count = 0;
  for (int i = 0; i <= k && i < numsSize; ++i) {
    if (table_find(t, nums[i])) {
      table_free(t);
      return true;
    }
    table_insert(t, nums[i]);
  }
  for (int i = k + 1; i < numsSize; ++i) {
    table_remove(t, nums[i - k - 1]);
    if (table_find(t, nums[i])) {
      table_free(t);
      return true;
    }
    table_insert(t, nums[i]);
  }
  table_free(t);
  return false;
}

int main() {
  table* t = table_init(3);
  table_insert(t, 1);
  // printf("find(12)=%d\n", table_find(t, 12));
  table_insert(t, 2);
  table_remove(t, 1);
  table_find(t, 1);
  // table_remove(t, 12);
  // printf("find(12)=%d\n", table_find(t, 12));
  // table_remove(t, 12);
  // printf("find(12)=%d\n", table_find(t, 12));
  // table_free(t);
  return 0;
}
