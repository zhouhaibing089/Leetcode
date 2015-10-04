#include <stdio.h>

/* single operator computation */
int compute(int lhs, int rhs, char op) {
  if (op == '+') {
    return lhs + rhs;
  }
  if (op == '-') {
    return lhs - rhs;
  }
  return 0;
}


int calculate(char* s) {
  static int i = 0;
  char c;
  int val = 0;
  char pop = '+';
  int n = 0;
  while (c = s[i++], c != 0) {
    if (c == ' ') {
      continue;
    } else if (c == '(') {
      n = calculate(s);
    } else if (c == ')') {
      break;
    } else if (c == '+' || c == '-') {
      val = compute(val, n, pop);
      pop = c;
      n = 0;
    } else {
      n = n * 10 + c - '0';
    }
  }
  if (c == 0) {
    /* reset function variable */
    i = 0;
  }
  return compute(val, n, pop);
}

int main() {
  printf("result=%d\n", calculate("(1 + (4 + 5 + 2) - 3) + (6 + 8)"));
  return 0;
}
