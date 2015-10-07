
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
  int n = numsSize - k + 1;
  *returnSize = n;
  if (k <= 1) {
    *returnSize = numsSize;
    return nums;
  }
  int* max = (int*)malloc(n * sizeof(int));
  max[0] = nums[0];
  for (int i = 1; i < k; ++i) {
    if (nums[i] > max[0]) {
      max[0] = nums[i];
    }
  }
  for (int i = k; i < numsSize; ++i) {
    if (nums[i] > max[i - k]) {
      max[i - k + 1] = nums[i];
      continue;
    }
    if (nums[i - k] < max[i - k]) {
      max[i - k + 1] = max[i - k];
      continue;
    }
    int m = nums[i];
    for (int j = (i - k + 1); j < i; ++j) {
      if (nums[j] > m) {
        m = nums[j];
      }
    }
    max[i - k + 1] = m;
  }
  return max;
}
