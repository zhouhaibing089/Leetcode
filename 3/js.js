var lengthOfLongestSubstring = function(s) {
    var max = 0;
    var current = 0;
    var except = [];
    for (var i = 0; i < s.length; ++i) {
        var index = except.indexOf(s[i]);
        if (index === -1) {
            except.push(s[i]);
            ++current;
            if (current > max) {
                max = current;
            }
        } else {
            except.splice(0, index + 1);
            except.push(s[i]);
            current = except.length;
        }
    }
    return max;
};
