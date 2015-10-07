#include <stdlib.h>
#include <stdio.h>

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

/* single operator computation */
int compute(int lhs, int rhs, char op) {
  if (op == '+') {
    return lhs + rhs;
  }
  if (op == '-') {
    return lhs - rhs;
  }
  if (op == '*') {
    return lhs * rhs;
  }
  if (op == '/') {
    return lhs / rhs;
  }
  return 0;
}

int calculate(char* s) {
  /* build the array of operators and operands */
  int n = 0;
  int i = 0;
  char c;
  IntSlice operators = int_slice();
  IntSlice operands = int_slice();
  int count = 0;
  while(c = s[i++], c != 0) {
    if (c == ' ') {
      continue;
    }
    if (c == '+' || c == '-' || c == '*' || c == '/') {
      int_slice_set(&operators, count, c);
      int_slice_set(&operands, count, n);
      ++count;
      n = 0;
    } else {
      n = n * 10 + c - '0';
    }
  }
  int_slice_set(&operands, count, n);
  // ====== DEBUG ======
  // for (int i = 0; i <= count; ++i) {
  //   printf("%d ", operands.slice[i]);
  // }
  // printf("\n");
  // for (int i = 0; i < count; ++i) {
  //   printf("%c ", operators.slice[i]);
  // }
  // printf("\n");
  // ======  END  ======
  int* ops = operators.slice;
  int* args = operands.slice;
  int index = 0;
  /* the first round */
  for (int i = 0; i < count; ++i) {
    if (ops[i] == '*' || ops[i] == '/') {
      args[index] = compute(args[i], args[i + 1], ops[i]);
      args[i + 1] = args[index];
    } else {
      args[index] = args[i];
      ops[index] = ops[i];
      ++index;
    }
  }
  args[index] = args[count];
  // ====== DEBUG ======
  // for (int i = 0; i <= index; ++i) {
  //   printf("%d ", operands.slice[i]);
  // }
  // printf("\n");
  // for (int i = 0; i < index; ++i) {
  //   printf("%c ", operators.slice[i]);
  // }
  // printf("\n");
  // ======  END  ======
  /* the second round */
  for (int i = 0; i < index; ++i) {
    args[i + 1] = compute(args[i], args[i + 1], ops[i]);
  }
  int val = args[index];
  free(args);
  free(ops);
  return val;
}

int main() {
  printf("result=%d\n", calculate("3 + 2 * 2 - 5 / 2"));
  return 0;
}
