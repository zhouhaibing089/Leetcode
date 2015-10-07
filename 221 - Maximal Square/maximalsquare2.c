int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
  int rs = matrixRowSize;
  int cs = matrixColSize;
  int max = 0;
  for (int j = 0; j < cs; ++j) {
    matrix[0][j] -= '0';
    if (matrix[0][j] == 1) {
      max = 1;
    }
  }
  for (int i = 1; i < rs; ++i) {
    for (int j = 0; j < cs; ++j) {
      matrix[i][j] -= '0';
      if (matrix[i][j] != 0) {
        matrix[i][j] += matrix[i - 1][j];
      }
    }
    /* inspect this line */
    int count = 0;
    for (int k = 0; k < cs; ++k) {
      if (matrix[i][k] > max) {
        ++count;
        if (count > max) {
          ++max;
          break;
        }
      } else {
        count = 0;
      }
    }
  }
  return max * max;
}
