#include <stdio.h>
#include <stdlib.h>


int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int* n = (int*)malloc(sizeof(int) * numsSize);
  int* l = (int*)malloc(sizeof(int) * numsSize);
  int* r = (int*)malloc(sizeof(int) * numsSize);
  l[0] = 1;
  r[numsSize - 1] = 1;
  for (int i = 1; i < numsSize; ++i) {
    l[i] = l[i - 1] * nums[i - 1];
    r[numsSize - i - 1] = r[numsSize - i] * nums[numsSize - i];
  }
  for (int i = 0; i < numsSize; ++i) {
    n[i] = l[i] * r[i];
  }
  free(l);
  free(r);
  return n;
}

int main() {
  int a[4] = {1, 2, 3, 4};
  int size;
  int* b = productExceptSelf(a, 4, &size);
  for (int i = 0; i < size; ++i) {
    printf("%d ", b[i]);
  }
  printf("\n");
  return 0;
}
