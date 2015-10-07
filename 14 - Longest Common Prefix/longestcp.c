#include <stdio.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {

    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    // empty string list
    if (strsSize == 0) {
        return "";
    }
    // tracking pointer
    int p = -1;
    // the first string
    char* first = strs[0];
    // only one string
    if (strsSize == 1) {
        return first;
    }
    while (first[p + 1] != 0) {
        bool same = true;
        for (int i = 1; i < strsSize; ++i) {
            char* str = strs[i];
            if (str[p + 1] == 0 || str[p + 1] != first[p + 1]) {
                same = false;
                break;
            }
        }
        if (same) {
            ++p;
        } else {
            break;
        }
    }
    if (p == -1) {
        return "";
    }
    char* result = (char*)malloc(sizeof(char) * (p + 2));
    strncpy(result, first, p + 1);
    result[p + 1] = 0;
    return result;
}
