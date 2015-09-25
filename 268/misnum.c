

int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += (i - nums[i]);
    }
    return sum + numsSize;
}
