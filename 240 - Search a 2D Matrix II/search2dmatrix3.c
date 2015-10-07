bool searchMatrix2(int** matrix, int rs, int cs, int target, int offset) {
  if (rs == 0 || cs == 0) {
    return false;
  }
  int mr = rs / 2;
  int mc = cs / 2;
  int num = matrix[mr][mc + offset];
  if (num == target) {
    return true;
  } else if (num < target) {
    return searchMatrix2(matrix, mr + 1, cs - mc - 1, target, mc + 1 + offset)
      || searchMatrix2(matrix + mr + 1, rs - mr - 1, cs, target, offset);
  } else {
    return searchMatrix2(matrix, rs, mc, target, offset)
      || searchMatrix2(matrix, mr, cs - mc, target, mc + offset);
  }
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  return searchMatrix2(matrix, matrixRowSize, matrixColSize, target, 0);
}
