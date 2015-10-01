#include <stdlib.h>

#define INIT_CAPACITY 2

/* a dynamic array holds int values */
typedef struct IntArray IntArray;
/* a dynamic array holds pointers */
typedef struct PtrArray PtrArray;

struct IntArray {
  int capacity;
  int* array;
};

struct PtrArray {
  int capacity;
  void** array;
};

/* create an int array with default capacity */
IntArray int_array() {
  IntArray i_arr;
  i_arr.capacity = INIT_CAPACITY;
  i_arr.array = (int*)malloc(i_arr.capacity * sizeof(int));
  return i_arr;
}

/* create a pointer array with default capacity */
PtrArray ptr_array() {
  PtrArray p_arr;
  p_arr.capacity = INIT_CAPACITY;
  p_arr.array = (void**)malloc(p_arr.capacity * sizeof(void*));
  return p_arr;
}

/* set value at the index */
void int_array_set(IntArray* array_ptr, int index, int value) {
  if (index >= array_ptr->capacity) {
    array_ptr->capacity *= 2;
    int* narray = (int*)malloc(array_ptr->capacity * sizeof(int));
    for (int i = 0; i < index; ++i) {
      narray[i] = array_ptr->array[i];
    }
    free(array_ptr->array);
    array_ptr->array = narray;
  }
  array_ptr->array[index] = value;
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
void int_array_free(IntArray* array_ptr) {
  free(array_ptr->array);
}

/* free the allocated memory */
void ptr_array_free(PtrArray* array_ptr) {
  free(array_ptr->array);
}
