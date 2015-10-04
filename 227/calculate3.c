#include <stdlib.h>
#include <stdio.h>

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
  /* status track variable */
  int n = 0;    // current number
  int sp = 0;   // scan pointer
  char ops[2];  // track operators
  int args[2];  // track arguments
  int p = 0;    // points to the current ops
  /* initialization */
  ops[0] = '+';
  args[0] = 0;
  char c;
  int i = 0;
  /* scan this string */
  while(c = s[i++], c != 0) {
    if (c == ' ') {
      continue;
    }
    /* we meet operator */
    if (c == '+' || c == '-' || c == '*' || c == '/') {
      /* if previous operator has first privilege */
      if (ops[p] == '*' || ops[p] == '/') {
        n = compute(args[p], n, ops[p]);
        --p;
      }
      /* summary above */
      if (c == '+' || c == '-') {
        args[p] = compute(args[p], n, ops[p]);
        ops[p] = c;
      } else {
        args[p + 1] = n;
        ops[p + 1] = c;
        ++p;
      }
      n = 0;
    } else {
      n = n * 10 + c - '0';
    }
    // ====== DEBUG ======
    // printf("Args: [");
    // for (int j = 0; j <= p; ++j) {
    //   printf("%d, ", args[j]);
    // }
    // printf("]\n");
    // printf("Ops: [");
    // for (int j = 0; j <= p; ++j) {
    //   printf("%c, ", ops[j]);
    // }
    // printf("]\n");
    // ======  END  =======
  }
  if (ops[p] == '*' || ops[p] == '/') {
    n = compute(args[p], n, ops[p]);
  }
  return compute(args[0], n, ops[0]);
}

int main() {
  printf("result=%d\n", calculate("3 + 2 * 2 - 5 / 2"));
  return 0;
}
