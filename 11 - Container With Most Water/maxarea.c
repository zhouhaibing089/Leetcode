#include <stdio.h>

int maxArea(int* height, int heightSize);

int main() {
    int height[3] = {3, 2, 1};
    return 0;
}

/*
 * The O(n^2) solution will not be accepted.
 */
int maxArea(int* height, int heightSize) {
    int max = 0;
    int l = 0;
    int r = heightSize - 1;
    while (l < r) {
        int tmp = (r - l) * (height[l] > height[r] ? height[r] : height[l]);
        if (tmp > max) {
            max = tmp;
        }
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return max;
}
