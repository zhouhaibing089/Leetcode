#include <stdio.h>
#include <limits.h>

int reverse(int x);

int main() {
    printf("%d\n", reverse(0));
    return 0;
}

/*
 * special case:
 *   1. the last digit is 0
 *   2. the number may be negative
 *   2. overflow behavior
 */
int reverse(int x) {
    int negative = x < 0 ? 1 : 0;
    /* the result */
    int result = 0;
    /* trim the last zero: #1 */
    while (x != 0 && x % 10 == 0) {
        x /= 10;
    }
    /* make the negative to be positive: #2 */
    if (negative == 1) {
        x = -x;
    }
    /* do the reverse */
    while (x != 0) {
        if ((INT_MAX - x % 10) / 10 < result) {
            return 0;
        }
        result = result * 10 + x % 10;
        x /= 10;

    }
    return negative == 0 ? result : -result;
}
