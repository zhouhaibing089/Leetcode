#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int *nums, int numsSize) {
  int size = sizeof(int) * 8;
  int bits[size];
  int bits2[size];
  for (int i = 0; i < size; ++i) {
    bits[i] = 0;
    bits2[i] = 0;
  }
  for (int i = 1; i <= (numsSize - 1); ++i) {
    int n = i;
    int j = 0;
    while (n != 0) {
      if (n % 2 == 1) {
        bits[j] = bits[j] + 1;
      }
      n = n / 2;
      ++j;
    }
  }
  for (int i = 0; i < numsSize; ++i) {
    int n = nums[i];
    int j = 0;
    while (n != 0) {
      if (n % 2 == 1) {
        ++bits2[j];
      }
      n = n >> 1;
      ++j;
    }
  }
  int sub = 0;
  for (int i = 0; i < size; ++i) {
    int n = 1 << i;
    if (bits2[i] > bits[i]) {
      sub += n;
    }
  }
  return sub;
}

int main() {
  int sample[] = {
    14,16,12,1,16,17,6,8,5,19,16,13,16,3,11,16,4,16,9,7
  };
  printf("result=%d\n", findDuplicate(sample, 20));
  return 0;
}
