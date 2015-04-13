### Median of Two Sorted Arrays

There are two sorted arrays `A` and `B` of size `m` and `n` respectively. Find the median of the two sorted arrays. The overall run time complexity should be `O(log (m+n))`.

### 思路

问题简化成: 给定两个有序数组: `A[0..m)`和`B[0..n)`, 找到第`k`大的元素。

1.  取`v = A[⎿m/2⏌]`, 在`B`中找到第一个数`B[i]`, 使得`B[i] <= v`

2.  此时两个数组中一共有`left = ⎿m/2⏌- 1 + i`个数小于等于`v`

    2.1 如果`k = left + 1`, 则返回`v`

    2.2 如果`k <= left`: 重置`A = A[0..⎿m/2⏌), B = B[0..i]`, 重复第一步

    2.3 否则重置`A = [⎿m/2⏌..m), B = B(i..n), k = k - left - 1`, 重复第一步
