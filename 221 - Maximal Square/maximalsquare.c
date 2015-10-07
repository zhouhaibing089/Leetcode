int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
  int rs = matrixRowSize;
  int cs = matrixColSize;
  int max = 0;
  int width = 1;
  for (int i = 0; i <= (rs - width); ++i) {
    for (int j = 0; j <= (cs - width); ++j) {
      int val = 0;
      for (int k = 0; k < width; ++k) {
        for (int l = 0; l < width; ++l) {
          val += (matrix[i + k][j + l] - '0');
        }
      }
      //printf("val=%d\n", val);
      if (val == (width * width)) {
        max = val;
        i = -1;
        ++width;
        break;
      }
    }
  }
  return max;
}
