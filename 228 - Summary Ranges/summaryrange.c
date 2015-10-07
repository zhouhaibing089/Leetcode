#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
  char** ranges = (char**)malloc(sizeof(char*) * numsSize);
  int index = 0;
  if (numsSize == 0) {
    *returnSize = 0;
    return NULL;
  }
  int start = nums[0];
  // store a range
  char* r = (char*)malloc(sizeof(char) * 30);
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] != (nums[i - 1] + 1)) {
      if (nums[i - 1] == start) {
        sprintf(r, "%d", start);
      } else {
        sprintf(r, "%d->%d", start, nums[i - 1]);
      }
      ranges[index++] = r;
      start = nums[i];
      /* reallocate the memory */
      r = (char*)malloc(sizeof(char) * 30);
    }
  }
  /* single element*/
  if (nums[numsSize - 1] == start) {
    sprintf(r, "%d", start);
  } else {
    sprintf(r, "%d->%d", start, nums[numsSize - 1]);
  }
  ranges[index++] = r;
  *returnSize = index;
  return ranges;
}
