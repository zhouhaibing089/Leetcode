#include <stdlib.h>
#include <stdio.h>

/* a dynamic array holds pointers */
typedef struct PtrArray PtrArray;

struct PtrArray {
  int capacity;
  void** array;
};

/* create a pointer array with default capacity */
PtrArray ptr_array() {
  PtrArray p_arr;
  p_arr.capacity = 2;
  p_arr.array = (void**)malloc(p_arr.capacity * sizeof(void*));
  return p_arr;
}

/* set value at the index */
void ptr_array_set(PtrArray* array_ptr, int index, void* value) {
  if (index >= array_ptr->capacity) {
    array_ptr->capacity *= 2;
    void** narray = (void**)malloc(array_ptr->capacity * sizeof(void*));
    for (int i = 0; i < index; ++i) {
      narray[i] = array_ptr->array[i];
    }
    free(array_ptr->array);
    array_ptr->array = narray;
  }
  array_ptr->array[index] = value;
}

/* free the allocated memory */
void ptr_array_free(PtrArray* array_ptr) {
  free(array_ptr->array);
}

int compare(const void* p1, const void* p2) {
  return (*(int*)p1) - (*(int*)p2);
}

int** twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int s = 0;
  PtrArray result = ptr_array();
  /* find two number sums to */
  for (int i = 0; i < (numsSize - 1); i++) {
    for (int j = (i + 1); j < numsSize; j++) {
      if ((nums[i] + nums[j]) == target) {
        int* array = (int*)malloc(sizeof(int) * 4);
        array[2] = nums[i];
        array[3] = nums[j];
        ptr_array_set(&result, s++, array);
      }
      int k = j + 1;
      for (; k < numsSize; ++k) {
        if (nums[k] != nums[j]) {
          break;
        }
      }
      j = k - 1;
    }
    int k = i + 1;
    for (; k < (numsSize - 1); ++k) {
      if (nums[k] != nums[i]) {
        break;
      }
    }
    i = k - 1;
  }
  *returnSize = s;
  return (int**)result.array;
}

int** threeSum(int* nums, int numsSize, int target, int* returnSize) {
  int s = 0;
  PtrArray result = ptr_array();
  for (int i = 0; i < (numsSize - 2); ++i) {
    int size;
    int** r = twoSum(nums + i + 1, numsSize - 1 - i, target - nums[i], &size);
    if (size == 0) {
      continue;
    }
    for (int j = 0; j < size; ++j) {
      r[j][1] = nums[i];
      ptr_array_set(&result, s++, r[j]);
    }
    int k = i + 1;
    for (; k < (numsSize - 2); ++k) {
      if (nums[k] != nums[i]) {
        break;
      }
    }
    i = k - 1;
  }
  *returnSize = s;
  return (int**)result.array;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
  /* sort */
  qsort(nums, numsSize, sizeof(int), compare);
  /* result */
  int s = 0;
  PtrArray result = ptr_array();
  for (int i = 0; i < (numsSize - 3); ++i) {
    int size;
    /* find three sum */
    int** r = threeSum(nums + i + 1, numsSize - 1 - i, target - nums[i], &size);
    if (size == 0) {
      continue;
    }
    for (int j = 0; j < size; ++j) {
      r[j][0] = nums[i];
      ptr_array_set(&result, s++, r[j]);
    }
    int k = i + 1;
    for (; k < (numsSize - 3); ++k) {
      if (nums[k] != nums[i]) {
        break;
      }
    }
    i = k - 1;
  }
  *returnSize = s;
  return (int**)result.array;
}

int main() {
  int a[8] = {5, 5, 3, 5, 1, -5, 1, -2};
  int size;
  int** r = fourSum(a, 8, 0, &size);
  for (int i = 0; i < size; ++i) {
    printf("(%d %d %d %d)\n", r[i][0], r[i][1], r[i][2], r[i][3]);
  }
  return 0;
}
