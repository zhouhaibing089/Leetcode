#include <stdbool.h>
#include <stdio.h>

bool is_match(char *s, char *p);

int main() {
    printf ("%d\n", is_match("ab", ".*.."));
    return 0;
}

/*
 * `.`: match any character
 * `*`: zero or more of the preceding character
 */
bool is_match(char *s, char *p) {
    /* source pointer */
    int sp = 0;
    /* pattern pointer */
    int pp = 0;
    /* traverse the source */
    while (s[sp++] != 0) {
        printf("sp = %d, pp = %d\n", sp - 1, pp);
        char sc = s[sp - 1];
        char pc = p[pp];
        /* partial match */
        if (pc == 0) {
            printf("partial match\n");
            return false;
        }
        // the same or the dot match
        if (sc == pc || pc == '.') {
            printf("same or dot match\n");
            ++pp;
            continue;
        }
        // the star match: a = a*
        if (pp > 0 && pc == '*' && (p[pp - 1] == sc || p[pp - 1] == '.')) {
            printf("star match\n");
            continue;
        }
        // end of star match: a = *a
        if (p[pp + 1] != 0 && pc == '*' && (p[pp + 1] == sc || p[pp + 1] == '.')) {
            printf("end of star match\n");
            pp += 2;
            continue;
        }
        // ignore star
        if (p[pp + 1] != 0 && p[pp + 1] == '*') {
            printf("star get ingored\n");
            pp += 2;
            // reset the source pointer
            sp -= 1;
            continue;
        }
        printf("not match\n");
        return false;
    }
    printf("out of the loop, sp= %d, pp = %d\n", sp, pp);
    if (p[pp] == 0) {
        return true;
    }
    int sign = 0;
    if (p[pp] == '*') {
        sign = 1;
        ++pp;
    }
    char last = s[sp - 2];
    while (p[pp] != 0 && p[pp + 1] != 0) {
        if (p[pp + 1] != '*') {
            printf("not star: pp = %d\n", pp + 1);
            return false;
        }
        pp += 2;
    }
    printf("last pp = %d, sp = %d, sign= %d\n", pp, sp - 2, sign);
    return p[pp] == 0 || (p[pp] == last && sign == 1);
    // return p[pp] == 0 || (p[pp] == '*' && p[pp + 1] == 0) || (p[pp] == '*' && p[pp + 1] == p[pp - 1] && p[pp + 2] == 0);
}
