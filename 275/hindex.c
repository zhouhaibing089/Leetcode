int hIndex(int* citations, int citationsSize) {
    for (int i = citationsSize; i >= 1; --i) {
        if (citations[citationsSize - i] >= i) {
            return i;
        }
    }
    return 0;
}
