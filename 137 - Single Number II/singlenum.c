/*******************************************************************************
 *  Given an array of integers, every element appears three times except for one.
 *  Find that single one
 *******************************************************************************/
int singleNumber(int* nums, int numsSize) {
  int a = 0, b = 0;
  for(int i = 0; i < numsSize; ++i){
    int c = nums[i];
    int ta = (~a & b & c) | (a & ~b & ~c);
    b = (~a & ~b & c) | (~a & b & ~c);
    a=ta;
  }
  return a | b;
}
