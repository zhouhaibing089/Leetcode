#include <stdio.h>

int romanToInt(char* s);


int main() {

    return 0;
}

int romanToInt(char* s) {
    int i = 0;
    // current character
    char c;
    // previous character
    char prev = 0;
    int num = 0;
    while ((c = s[i++]) != 0) {
        if (c == 'M') {
            num += 1000;
            if (prev == 'C') {
                num -= 200;
            }
        }
        else if (c == 'D') {
            num += 500;
            if (prev == 'C') {
                num -= 200;
            }
        }
        else if (c == 'C') {
            num += 100;
            if (prev == 'X') {
                num -= 20;
            }
        }
        else if (c == 'L') {
            num += 50;
            if (prev == 'X') {
                num -= 20;
            }
        }
        else if (c == 'X') {
            num += 10;
            if (prev == 'I') {
                num -= 2;
            }
        }
        else if (c == 'V') {
            num += 5;
            if (prev == 'I') {
                num -= 2;
            }
        }
        else if (c == 'I') {
            num += 1;
        }
        prev = c;
    }
    return num;
}
