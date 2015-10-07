#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// sum = sum + sum * 2 + sum * 8 + ctx - sum;
int countDigitOne(int n) {
  if (n <= 0) {
    return 0;
  }
  if (n < 10) {
    return 1;
  }
  long ctx = 10;
  int ctx_count = 1;
  while (n >= (ctx * 10)) {
    ctx_count = ctx_count * 10 + ctx;
    ctx *= 10;
  }
  int count = ctx_count;
  if (n >= (2 * ctx)) {
    count += count * 2 + count * (n / ctx - 2) + ctx - count;
    int low_n = countDigitOne(n % ctx);
    count += low_n;
  } else {
    int low_n = countDigitOne(n - ctx);
    count += low_n * 2 + (n - (ctx - 1)) - low_n;
  }
  return count;
}

int main() {
  printf("%d\n", countDigitOne(1410065408));
  return 0;
}
