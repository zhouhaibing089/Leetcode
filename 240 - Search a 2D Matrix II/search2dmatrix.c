#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix2(int** matrix, int rs, int cs, int target, int offset) {
  printf("rs=%d, cs=%d, offset=%d\n", rs, cs, offset);
  if (rs == 1 && cs == 1) {
    printf("inspect matrix[%d][%d]=%d\n", 0, offset, matrix[0][offset]);
    return matrix[0][offset] == target;
  }
  if (rs == 0 || cs == 0) {
    return false;
  }
  int mr = rs / 2;
  int mc = cs / 2;
  int num = matrix[mr][mc + offset];
  printf("inspect matrix[%d][%d]=%d\n", mr, mc, matrix[mr][mc + offset]);
  /* now we got the matrix like this */
  // |-----|-----|
  // |  A  |  B  |
  // |----num----|
  // |  C  |  D  |
  // |-----|-----|
  if (num == target) {
    return true;
  } else if (num < target) {
    /* target can only appear in B, C or D */
    return searchMatrix2(matrix, mr + 1, cs - mc - 1, target, mc + 1 + offset)
      || searchMatrix2(matrix + mr + 1, rs - mr - 1, cs, target, offset);
  } else {
    /* target can only appear in A, B or C */
    return searchMatrix2(matrix, rs, mc, target, offset)
      || searchMatrix2(matrix, mr, cs - mc, target, mc + offset);
  }
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  return searchMatrix2(matrix, matrixRowSize, matrixColSize, target, 0);
}

int main() {
  int **matrix = (int**)malloc(1 * sizeof(int*));
  // int r1[5] = {1,   4,  7, 11, 15};
  // int r2[5] = {2,   5,  8, 12, 19};
  // int r3[5] = {3,   6,  9, 16, 22};
  // int r4[5] = {10, 13, 14, 17, 24};
  // int r5[5] = {18, 21, 23, 26, 30};
  int r1[5] = {1, 2, 3, 4, 5};
  matrix[0] = r1;
  // matrix[1] = r2;
  // matrix[2] = r3;
  // matrix[3] = r4;
  // matrix[5] = r5;
  printf("result=%d\n", searchMatrix(matrix, 1, 5, 4));
  return 0;
}
