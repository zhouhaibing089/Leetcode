#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x);


int main() {
    printf("%d\n", isPalindrome(1000021));
    return 0;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int base = 1;
    int copy = x;
    while ((copy /= 10) != 0) {
        base *= 10;
    }
    if (base == 1) {
        return true;
    }
    while (base > 1) {
        //printf("x = %d, base = %d\n", x, base);
        int first = x / base;
        int last = x % 10;
        if (first != last) {
            return false;
        }
        x = (x - first * base) / 10;
        base /= 100;
    }
    return true;
}
