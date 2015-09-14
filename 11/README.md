### Container with Most Water

给定n个非负数, 组成n个数据对`(i, Ai)`, 找出其中两个数据对`(i, Ai), (j, Aj)`使得`(j - i) * min(Ai, Aj)`具有最大值.

### 解决方案

1.  初始化`l = 0, r = n - 1, max = 0`
2.  计算`B = (r - l) * min(Al, Aj)`, 如果`B > max`则`max = B`
    2.1 如果`Al > Aj`, 则让`j--`
    2.2 如果`Al <= Aj`, 则让`l++`
    2.3 重复第2步
