#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int numSquares(int n) {
    int* store = (int*)malloc((n + 1) * sizeof(int));
    store[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int sq = floor(sqrt(i));
        if ((sq * sq) == i) {
            store[i] = i;
            continue;
        }
        store[i] = INT_MAX;
        // calculate the value
        for (int j = 1; j <= sq; ++j) {
            int next_value = i - j * j;
            if (store[next_value] < store[i]) {
                store[i] = store[next_value];
            }
        }
        store[i] = store[i] + 1;
    }
    int value = store[n];
    free(store);
    return value;
}

int main() {
    printf("%d\n", numSquares(9600));
    return 0;
}
