int mySqrt(int x) {
  if (x < 2) {
    return x;
  }
  int p1 = 0;
  int p2 = 0;
  int n = x >> 1;
  while (n != p1 && n != p2) {
    p2 = p1;
    p1 = n;
    n = (n + x / n) >> 1;
  }
  return n < p1 ? n : p1;
}
