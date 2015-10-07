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
  /* appears many times */
  int count;
  /* points to the next entry */
  entry* next;
};

struct table {
  /* buckets */
  entry** buckets;
  /* the prime */
  int prime;
};

/* create table */
table* table_init(int s) {
  /* primary table */
  static int pt[10] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29
  };
  table* t = (table*)malloc(sizeof(table));
  t->buckets = NULL;
  for (int i = 0; i < 10; ++i) {
    if (s <= pt[i]) {
      t->prime = pt[i];
      t->buckets = (entry**)malloc(sizeof(entry*) * pt[i]);
      break;
    }
  }
  if (t->buckets == NULL) {
    t->prime = pt[9];
    t->buckets = (entry**)malloc(sizeof(entry*) * pt[9]);
  }
  for (int i = 0; i < t->prime; ++i) {
    t->buckets[i] = NULL;
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
  /* construct the new node */
  entry* ne = (entry*)malloc(sizeof(entry));
  ne->val = val;
  ne->count = 1;
  ne->next = NULL;
  /* set as the first */
  if (e == NULL) {
    t->buckets[index] = ne;
    return;
  }
  if (e->val == val) {
    ++(e->count);
    return;
  }
  entry* pe = e;
  e = e->next;
  while (e != NULL && e->val != val) {
    pe = e;
    e = e->next;
  }
  /* not found */
  if (e == NULL) {
    pe->next = ne;
  } else {
    ++(e->count);
    free(ne);
  }
}

/* remove */
void table_remove(table* t, int val) {
  int index = val % t->prime;
  if (index < 0) {
    index = 0 - index;
  }
  entry* e = t->buckets[index];
  /* not found */
  if (e == NULL) {
    return;
  }
  if (e->val == val) {
    /* check multi occurence */
    if (e->count == 1) {
      t->buckets[index] = e->next;
      free(e);
    } else {
      --(e->count);
    }
    return;
  }
  entry* pe = e;
  e = e->next;
  while (e != NULL && e->val != val) {
    pe = e;
    e = e->next;
  }
  /* not found */
  if (e == NULL) {
    return;
  }
  /* check multi occurence */
  if (e->count == 1) {
    pe->next = e->next;
    free(e);
  } else {
    --(e->count);
  }
}

/* find */
bool table_find(table* t, int val) {
  int index = val % t->prime;
  if (index < 0) {
    index = 0 - index;
  }
  entry* e = t->buckets[index];
  while (e != NULL) {
    if (e->val == val) {
      return true;
    }
    e = e->next;
  }
  return false;
}

/* free the allocated memory */
void table_free(table* t) {
  for (int i = 0; i < t->prime; ++i) {
    /* free each bucket */
    entry* e = t->buckets[i];
    while (e != NULL) {
      entry* c = e;
      e = e->next;
      free(c);
    }
  }
  free(t->buckets);
  free(t);
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  table* t = table_init(k + 1);
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
  table* t = table_init(2);
  table_insert(t, 1);
  table_insert(t, 0);
  table_remove(t, 1);
  table_insert(t, 1);
  table_remove(t, 0);
  table_insert(t, 1);
  printf("find()=%d\n", table_find(t, 12));
  table_insert(t, 12);
  table_remove(t, 12);
  printf("find(12)=%d\n", table_find(t, 12));
  table_remove(t, 12);
  printf("find(12)=%d\n", table_find(t, 12));
  table_free(t);
  return 0;
}
