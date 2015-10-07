var convert = function(s, nRows) {
    if (nRows === 1) {
        return s;
    }

    var cycle = nRows + nRows - 2;
    var answer = [];

    var i = 0;
    var round = 0;
    var first = 0;
    var second = 0;
    for (i = 0; i < nRows; ++i) {
        round = -1;
        while (true) {
            ++round;
            first = round * cycle + i;
            second = (round + 1) * cycle - i;

            if (first >= s.length) {
                break;
            }
            answer.push(s.charAt(first));
            if (second >= s.length) {
                break;
            }
            if ((second - first) === cycle) {
                continue;
            }
            if (first === second) {
                continue;
            }
            answer.push(s.charAt(second));
        }
    }
    return answer.join("");
};
