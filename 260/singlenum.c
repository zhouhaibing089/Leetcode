

int* singleNumber(int* nums, int numsSize, int* returnSize) {
  int x = 0;
  int y = 0;
  int xor = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    xor ^= nums[i];
  }
  // now we can assume x ^ y = xor
  int marker = 1;
  while ((marker & xor) != marker) {
    marker = marker << 1;
  }
  // now marker tells the lowest bit 1 in xor
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] & marker) {
      x = x ^ nums[i];
    }
  }
  y = x ^ xor;
  int* r = (int*)malloc(2 * sizeof(int));
  r[0] = x;
  r[1] = y;
  *returnSize = 2;
  return r;
}
