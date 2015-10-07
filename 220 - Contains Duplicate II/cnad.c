bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
  if (t < 0) {
    t = -t;
  }
  for (int i = 0; i < (numsSize - 1); ++i) {
    for (int j = 1; j <= k && (i + j) < numsSize; ++j) {
      int diff = nums[i] - nums[i + j];
      if (diff >= -t && diff <= t) {
        return true;
      }
    }
  }
  return false;
}
