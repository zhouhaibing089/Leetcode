#include <stdbool.h>
#include <stdio.h>

bool is_match(char *s, char *p);

int main() {
    printf ("%d\n", is_match("a", ".*..a*"));
    return 0;
}

/*
 * `.`: match any character
 * `*`: zero or more of the preceding character
 */
bool is_match(char *s, char *p) {
    bool match = false;
    // base case #1: both reach to the end
    if (s[0] == 0 && p[0] == 0) {
        printf("base case #1 reached\n");
        return true;
    }
    // base case #2: 'a' == 'a' || 'a' == '.'
    if (s[0] == p[0] || (s[0] != 0 && p[0] == '.')) {
        printf("24: recursive to: s=%s, p=%s\n", s + 1, p + 1);
        match = is_match(s + 1, p + 1);
    }
    if (match) {
        printf("base case #2 reached\n");
        return true;
    }
    // base case #3: 'a' == 'a*'
    if (p[0] != 0 && p[1] != 0 && p[1] == '*') {
        // as zero times
        printf("34: recursive to: s=%s, p=%s\n", s, p + 2);
        match = is_match(s, p + 2);
        if (match) {
            printf("base case #3 as zero time reached\n");
            return true;
        }
        // as one or more times
        if (s[0] == p[0] || (p[0] == '.' && s[0] != 0)) {
            printf("42: recursive to: s=%s, p=%s\n", s + 1, p);
            match = is_match(s + 1, p);
            if (match) {
                printf("base case #3 as one or more times reached\n");
                return match;
            }
        }
    }
    return false;
}
