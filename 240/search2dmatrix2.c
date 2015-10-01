
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  int rs = matrixRowSize;
  int cs = matrixColSize;

  int r = 0;
  int c = cs - 1;

  while (r < rs && c >= 0) {
    if (matrix[r][c] == target) {
      return true;
    }
    if (matrix[r][c] > target) {
      --c;
    } else {
      ++r;
    }
  }
  return false;
}
