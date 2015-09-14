#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num);

int main() {
    char* result = intToRoman(13);
    printf("%s\n", result);
    free(result);
    return 0;
}

/*
 * M = 1000, D = 500,
 * C = 100, L = 50,
 * X = 10, V = 5,
 * I = 1
 */
char* intToRoman(int num) {
    char* result = (char*)malloc(sizeof(char) * 100);
    int i = 0;
    int c = 0;
    // #1: the M subtract => 1000
    while (num >= 1000) {
        printf("#1\n");
        result[i++] = 'M';
        num -= 1000;
    }
    // #2: the D subtract => 500
    if (num >= 500) {
        printf("#2\n");
        result[i++] = 'D';
        num -= 500;
    }
    // #3: the C subtract => 100
    c = 0;
    while (num >= 100) {
        num -= 100;
        ++c;
        if (c == 4) {
            // #3.1: 400 = 500 - 100, DDDD => CD
            printf("#3.1\n");
            result[i - 2] = 'D';
            --i;
            // #3.1.1: 900 = 1000 - 100, DCD = CM
            if (result[i - 3] == 'D') {
                printf("#3.1.1\n");
                result[i - 3] = 'C';
                result[i - 2] = 'M';
                --i;
            }
            break;
        } else {
            // #3.2: => 100
            printf("#3.2\n");
            result[i++] = 'C';
        }
    }
    // #4: the L subtract => 50
    if (num >= 50) {
        printf("#4\n");
        result[i++] = 'L';
        num -= 50;
    }
    // #5: the X subtract => 10
    c = 0;
    while (num >= 10) {
        num -= 10;
        ++c;
        if (c == 4) {
            // #5.1: 40 = 50 - 10, XXXX = XL
            printf("#5.1\n");
            result[i - 2] = 'L';
            --i;
            // #5.1.1: 90 = 100 - 10, LXL = XC
            if (result[i - 3] == 'L') {
                printf("#5.1.1\n");
                result[i - 3] = 'X';
                result[i - 2] = 'C';
                --i;
            }
            break;
        } else {
            // #5.2: => 10
            printf("#5.2\n");
            result[i++] = 'X';
        }
    }
    // #6: the V subtract => 5
    if (num >= 5) {
        printf("#6\n");
        result[i++] = 'V';
        num -= 5;
    }
    // #7: the I subtract => 1
    c = 0;
    while (num >= 1) {
        num -= 1;
        ++c;
        if (c == 4) {
            // #7.1: 4 = 5 - 1, IIII = IV
            printf("#7.1\n");
            result[i - 2] = 'V';
            --i;
            // #7.1.1: 9 = 10 - 1, VIV = IX
            if (result[i - 3] == 'V') {
                printf("#7.1.1\n");
                result[i - 3] = 'I';
                result[i - 2] = 'X';
                --i;
            }
            break;
        } else {
            // #7.2: => 1
            printf("#7.2\n");
            result[i++] = 'I';
        }
    }
    result[i] = 0;
    return result;
}
