#include <stdio.h>

int addDigits(int num) {
  if (num < 10) {
    return num;
  }
  return addDigits(num % 10 + addDigits(num / 10));
}

int main() {
  printf("result=%d\n", addDigits(38));
  return 0;
}
