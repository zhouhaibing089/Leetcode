#include <stdio.h>
#include <limits.h>

int matoi(char* str);

int main() {

}

/*
 * convert string to int
 */
int matoi(char* str) {
    if (str == NULL) {
        return 0;
    }
    /* the result */
    int result = 0;
    /* is the number negative */
    int negative = 0;
    /* do we get number */
    int flag = 0;
    /* max positive value */
    long pos_max = INT_MAX;
    /* max negative value */
    long neg_max = pos_max + 1;
    /* the string index pointer */
    int i = 0;
    /* the current character to be scanned */
    char c;
    /* does not reach to the end */
    while((c = str[i++]) != 0) {
        /* it is a number */
        if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
            || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'
            || c == '+' || c == '-') {
            /* the sign can only appear as the first character */
            if (flag == 1 && (c == '+' || c == '-')) {
                return 0;
            }
            /* set the flag if not set previously */
            if (flag == 0) {
                flag = 1;
            }
            /* the sign check */
            if (c == '-') {
                negative = 1;
                continue;
            }
            if (c == '+') {
                continue;
            }
            /* will overflow */
            if (negative == 0) {
                if ((pos_max - c + '0') / 10 < result) {
                    return INT_MAX;
                }
            }
            if (negative == 1) {
                if ((neg_max - c + '0') / 10 < result) {
                    return INT_MIN;
                }
            }
            result = result * 10 + (c - '0');
        }
        /* it is not a number but the flag is already set */
        else if (flag == 1) {
            break;
        }
        /* we have not met number */
        else {
            if (c == ' ') {
                continue;
            } else {
                return 0;
            }
        }
    }
    return negative == 0 ? result : -result;
}
