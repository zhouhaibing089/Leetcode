#include <math.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
  int* r = (int*)malloc(sizeof(int) * 2);
  int index = 0;
  int* visited = (int*)malloc(sizeof(int) * numsSize);
  for (int i = 0; i < numsSize; ++i) {
    visited[i] = 0;
  }
  for (int i = 0; i < numsSize; i++) {
    if (visited[i]) {
      continue;
    }
    int inspect = nums[i];
    visited[i] = 1;
    int min_count = numsSize / 3 + 1;
    int count = 1;
    for (int j = i + 1; j < numsSize; j++) {
      if (visited[j]) {
        continue;
      }
      if (nums[j] == nums[i]) {
        ++count;
        visited[j] = 1;
      }
    }
    if (count >= min_count) {
      r[index++] = nums[i];
    }
  }
  *returnSize = index;
  free(visited);
  return r;
}
