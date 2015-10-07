#include <stdlib.h>
#include <stdio.h>

int compare(const void* p1, const void* p2) {
    return (*(int*)p1) - (*(int*)p2);
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), compare);
    for (int i = citationsSize; i >= 1; --i) {
        if (citations[citationsSize - i] >= i) {
            return i;
        }
    }
    return 0;
}

int main() {
    int* test = (int*)malloc(5 * sizeof(int));
    test[0] = 3;
    test[1] = 0;
    test[2] = 6;
    test[3] = 1;
    test[4] = 5;
    printf("hIndex = %d\n", hIndex(test, 5));
    free(test);
    return 0;
}
