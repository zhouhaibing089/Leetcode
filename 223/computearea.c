int diff(int a, int b, int c, int d) {
  if (d < a || b < c) {
    return 0;
  }
  if (a >= c && d > a && b >= d) {
    return d - a;
  }
  if (c >= a && b > c && d >= b) {
    return b - c;
  }
  if (c >= a && d > c && b >= d) {
    return d - c;
  }
  if (a >= c && b > a && d >= b) {
    return b - a;
  }
  return 0;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  return (A - C) * (B - D) + (E - G) * (F - H) - diff(A, C, E, G) * diff(B, D, F, H);
}
