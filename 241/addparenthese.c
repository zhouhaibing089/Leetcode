#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 2

/* a dynamic array holds int values */
typedef struct IntArray IntArray;

struct IntArray {
  int capacity;
  int* array;
};

/* create an int array with default capacity */
IntArray int_array() {
  IntArray i_arr;
  i_arr.capacity = INIT_CAPACITY;
  i_arr.array = (int*)malloc(i_arr.capacity * sizeof(int));
  return i_arr;
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

/* free the allocated memory */
void int_array_free(IntArray* array_ptr) {
  free(array_ptr->array);
}

/* remove value at index */
IntArray int_array_rm(IntArray* array_ptr, int length, int index) {
  IntArray array = int_array();
  for (int i = 0; i < length; ++i) {
    if (i < index) {
      int_array_set(&array, i, array_ptr->array[i]);
    }
    if (i == index) {
      continue;
    }
    if (i > index) {
      int_array_set(&array, i - 1, array_ptr->array[i]);
    }
  }
  return array;
}

/* print the array */
void int_array_print(IntArray* array_ptr, int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", array_ptr->array[i]);
  }
  printf("\n");
}

void char_array_print(IntArray* array_ptr, int length) {
  for (int i = 0; i < length; ++i) {
    printf("%c ", array_ptr->array[i]);
  }
  printf("\n");
}


/* normalize the string into a list of operands and operators */
void normalize(char* s, IntArray* operands, IntArray* operators, int* size) {
  int n = 0;      // current number
  char c;         // current character to be inspected
  int i = 0;      // current index points to s
  int count = 0;  // how many operators do we got
  /* store the operands */
  while ((c = s[i++]) != 0) {
    if (c == '+' || c == '-' || c == '*') {
      /* we got a operator, reset the number and put it on stack */
      int_array_set(operands, count, n);
      int_array_set(operators, count, c);
      ++count;
      n = 0;
    } else {
      /* we got a number, increase it */
      n = n * 10 + c - '0';
    }
  }
  int_array_set(operands, count, n);
  *size = count;
}

int* diffWaysToCompute2(IntArray* operands, IntArray* operators, int size,
  int pos, int* returnSize) {
  // ====== DEBUG ======
  printf("Operands: ");
  int_array_print(operands, size + 1);
  printf("Operators: ");
  char_array_print(operators, size);
  printf("size=%d, pos=%d\n", size, pos);
  // ======  END  ======
  int count = 0;
  IntArray result = int_array();
  if (size == 0) {
    /* single operator */
    // ====== DEBUG ======
    printf("Single Operator: %d\n", operands->array[0]);
    // ======  END  ======
    int_array_set(&result, count++, operands->array[0]);
  } else {
    /* recursion, add parenthese at each operator position */
    for (int i = pos; i < size; ++i) {
      int op = operators->array[i];
      int lv = operands->array[i];
      int rv = operands->array[i + 1];
      int value = 0;
      if (op == '+') {
        value = lv + rv;
      } else if (op == '-') {
        value = lv - rv;
      } else {
        value = lv * rv;
      }
      IntArray new_operands = int_array_rm(operands, size + 1, i);
      IntArray new_operators = int_array_rm(operators, size, i);
      int_array_set(&new_operands, i, value);
      int sub_size;
      // ====== DEBUG ======
      printf("Recursive: round=%d, %d %c %d = %d\n", i, lv, op, rv, value);
      // ======  END  ======
      int* sub = diffWaysToCompute2(&new_operands, &new_operators, size - 1,
        i == 0 ? 0 : i - 1, &sub_size);
      for (int j = 0; j < sub_size; ++j) {
        // ====== DEBUG ======
        printf("Got: %d\n", sub[j]);
        // ======  END  ======
        int_array_set(&result, count++, sub[j]);
      }
      free(sub);
    }
  }
  *returnSize = count;
  return result.array;
}

int* diffWaysToCompute(char* input, int* returnSize) {
  IntArray operands = int_array();
  IntArray operators = int_array();
  int count = 0;
  /* normalize the string into operands and operators */
  normalize(input, &operands, &operators, &count);
  // ====== DEBUG ======
  printf("Operands: ");
  int_array_print(&operands, count + 1);
  printf("Operators: ");
  int_array_print(&operators, count);
  // ======  END  ======
  /* use the normalized data to compute */
  int* result = diffWaysToCompute2(&operands, &operators, count, 0, returnSize);
  int_array_free(&operands);
  int_array_free(&operators);
  return result;
}

int main() {
  int size;
  int* result = diffWaysToCompute("2*3-4*5", &size);
  for (int i = 0; i < size; ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  free(result);
  return 0;
}
