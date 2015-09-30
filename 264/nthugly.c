#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  return min;
}

// use dynamic programming
int nthUglyNumber(int n) {
  int* store = (int*)malloc(n * sizeof(int));
  store[0] = 1;
  int m2 = 0;
  int m3 = 0;
  int m5 = 0;
  int n2 = 2;
  int n3 = 3;
  int n5 = 5;
  for (int i = 1; i < n; ++i) {
    int r = min(n2, n3, n5);
    printf("%d\n", r);
    store[i] = r;
    if (r == n2) {
      n2 = 2 * store[++m2];
    }
    if (r == n3) {
      n3 = 3 * store[++m3];
    }
    if (r == n5) {
      n5 = 5 * store[++m5];
    }
  }
  int result = store[n - 1];
  free(store);
  return result;
}

int main() {
  nthUglyNumber(20);
  return 0;
}
