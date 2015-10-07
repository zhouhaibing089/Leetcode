#include <stdio.h>
#include <stdlib.h>

int threeSumClosest(int* nums, int numsSize, int target);

int compare(const void* p1, const void* p2) {
    return (*(int*)p1) - (*(int*)p2);
}

int main() {

    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int min = INT_MAX;
    int result = 0;
    // #1. sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < (numsSize - 2); ++i) {
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = abs(sum - target);
            if (diff == 0) {
                return target;
            }
            if (diff < min) {
                min = diff;
                result = sum;
            }
            if (sum <= target) {
                ++j;
            } else {
                --k;
            }
        }
    }
    return result;
}
