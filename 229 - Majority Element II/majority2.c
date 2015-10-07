#include <math.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
  int a, b;
  int ca = 0, cb = 0;
  for (int i = 0; i < numsSize; ++i){
    if (ca != 0 && a == nums[i]) {
      ++ca;
      continue;
    }
    if (cb != 0 && b == nums[i]) {
      ++cb;
      continue;
    }
    if (ca == 0) {
      a = nums[i];
      ++ca;
      continue;
    }
    if (cb == 0) {
      b = nums[i];
      ++cb;
      continue;
    }
    --ca;
    --cb;
  }
  int c1 = 0, c2 = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (ca > 0 && nums[i] == a) {
      ++c1;
    }
    if (cb > 0 && nums[i] == b) {
      ++c2;
    }
  }
  int* r = (int*)malloc(2 * sizeof(int));
  int i = 0;
  if (c1 > numsSize / 3) {
    r[i++] = a;
  }
  if (c2 > numsSize / 3) {
    r[i++] = b;
  }
  *returnSize = i;
  return r;
}
