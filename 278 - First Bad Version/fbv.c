#include <stdio.h>
#include <stdbool.h>

bool isBadVersion(int version) {
    return version >= 1;
}

int firstBadVersion2(int start, int end) {
    printf("Find: start=%d, end=%d\n", start, end);
    if (start == end) {
        if (isBadVersion(start)) {
            return start;
        } else {
            return start + 1;
        }
    }
    int middle = start + (end - start) / 2;
    if (isBadVersion(middle)) {
        return firstBadVersion2(start, middle);
    } else {
        return firstBadVersion2(middle + 1, end);
    }
}

int firstBadVersion(int n) {
    return firstBadVersion2(1, n);
}

int main() {
    printf("First Bad Version: %d\n", firstBadVersion(2));
    return 0;
}
