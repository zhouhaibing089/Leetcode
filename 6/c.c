char *convert(char *s, int nRows) {
    int len = strlen(s);
    int cycle = nRows + nRows - 2;
    char* answer = (char*)malloc(len + 1);
    int i = 0;
    int j = 0;
    int round = 0;
    int first = 0;
    int second = 0;

    answer[len] = 0;

    if (nRows == 1) {
        strcpy(answer, s);
        return answer;
    }

    for (i = 0; i < nRows; ++i) {
        round = -1;
        while (true) {
            ++round;
            first = round * cycle + i;
            second = (round + 1) * cycle - i;

            if (first >= len) {
                break;
            }
            answer[j++] = s[first];
            if (second >= len) {
                break;
            }
            if ((second - first) == cycle) {
                continue;
            }
            if (first == second) {
                continue;
            }
            answer[j++] = s[second];
        }
    }
    return answer;
}
