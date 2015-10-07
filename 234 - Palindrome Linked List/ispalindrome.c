#include <stdlib.h>
#include <stdbool.h>

#define INIT_CAPACITY 2

/* a dynamic slice holds int values */
typedef struct IntSlice IntSlice;

struct IntSlice {
  int capacity;
  int* slice;
};

/* create an int slice with default capacity */
IntSlice int_slice() {
  IntSlice i_arr;
  i_arr.capacity = INIT_CAPACITY;
  i_arr.slice = (int*)malloc(i_arr.capacity * sizeof(int));
  return i_arr;
}

/* set value at the index */
void int_slice_set(IntSlice* slice_ptr, int index, int value) {
  if (index >= slice_ptr->capacity) {
    slice_ptr->capacity *= 2;
    int* nslice = (int*)malloc(slice_ptr->capacity * sizeof(int));
    for (int i = 0; i < index; ++i) {
      nslice[i] = slice_ptr->slice[i];
    }
    free(slice_ptr->slice);
    slice_ptr->slice = nslice;
  }
  slice_ptr->slice[index] = value;
}

/* remove value at index */
IntSlice int_slice_rm(IntSlice* slice_ptr, int length, int index) {
  IntSlice slice = int_slice();
  for (int i = 0; i < length; ++i) {
    if (i < index) {
      int_slice_set(&slice, i, slice_ptr->slice[i]);
    }
    if (i == index) {
      continue;
    }
    if (i > index) {
      int_slice_set(&slice, i - 1, slice_ptr->slice[i]);
    }
  }
  return slice;
}

/* free the allocated memory */
void int_slice_free(IntSlice* slice_ptr) {
  free(slice_ptr->slice);
}

struct ListNode {
  int val;
  struct ListNode *next;
};

bool isPalindrome2(int* array, int size) {
  if (size <= 1) {
    return true;
  }
  if (size == 2) {
    return array[0] == array[1];
  }
  return array[0] == array[size - 1] && isPalindrome2(array + 1, size - 2);
}

bool isPalindrome(struct ListNode* head) {
  int count = 0;
  IntSlice slice = int_slice();
  struct ListNode* node = head;
  while (head != NULL) {
    int_slice_set(&slice, count++, head->val);
    head = head->next;
  }
  bool result = isPalindrome2(slice.slice, count);
  int_slice_free(&slice);
  return result;
}
