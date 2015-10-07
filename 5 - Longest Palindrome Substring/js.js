var longestPalindrome = function(s) {
    var length = s.length;

    var start = 0;
    var max = 1;
    var current = 1;

    var maxLeft = 0;
    var maxRight = 0;
    var stepSize = 0;

    var i = 1, j = 0;
    for (i = 1; i < length; ++i) {
        maxLeft = i;
        maxRight = length - i - 1;
        stepSize = maxLeft > maxRight ? maxRight : maxLeft;
        current = 1;
        for (j = 1; j <= stepSize; j++) {
            if (s[i - j] == s[i + j]) {
                current += 2;
            } else {
                break;
            }
        }
        if (current > max) {
            max = current;
            start = i - (max - 1) / 2;
        }
        if (s[i] != s[i - 1]) {
            continue;
        }
        maxLeft = i - 1;
        stepSize = maxLeft > maxRight ? maxRight : maxLeft;
        current = 2;
        for (j = 1; j <= stepSize; j++) {
            if (s[i - 1 - j] == s[i + j]) {
                current += 2;
            } else {
                break;
            }
        }
        if (current > max) {
            max = current;
            start = i - (max - 2) / 2 - 1;
        }
    }
    return s.substr(start, max);
};
