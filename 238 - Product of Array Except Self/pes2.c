int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int* n = (int*)malloc(sizeof(int) * numsSize);
  n[0] = 1;
  for (int i = 1; i < numsSize; ++i) {
    n[i] = n[i - 1] * nums[i - 1];
  }
  int tmp = 1;
  for (int i = 1; i <= numsSize; ++i) {
    n[numsSize - i] *= tmp;
    tmp *= nums[numsSize - i];
  }
  return n;
}
