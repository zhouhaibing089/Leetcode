#include <stdio.h>

int mySqrt(int x) {
  if (x == 0) {
    return 0;
  }
  int l = 1;
  int h = x;
  while (l < h) {
    int m = l + (h - l) / 2;
    printf("(l, m, h) = (%d %d %d)\n", l, m, h);
    int r = x / m;
    int s = x / (m + 1);
    if (r == m) {
      return m;
    }
    if (s == m) {
      return s;
    }
    if (m == l) {
      return h;
    }
    if (r > m) {
      l = m + 1;
    } else {
      h = m - 1;
    }
  }
  return l == h ? l : h;
}

int main(int argc, char** argv) {
  int x;
  sscanf(argv[1], "%d", &x);
  printf("sqrt(%d)=%d\n", x, mySqrt(x));
  return 0;
}
