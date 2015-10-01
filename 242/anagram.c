#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
  int ls = strlen(s);
  int lr = strlen(t);
  if (ls != lr) {
    return false;
  }
  int is[26] = {0};
  int it[26] = {0};
  for (int i = 0; i < ls; ++i) {
    ++is[s[i] - 'a'];
    ++it[t[i] - 'a'];
  }
  for (int i = 0; i < 26; ++i) {
    if (is[i] != it[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  printf("result=%d\n", isAnagram("rat", "car"));
  return 0;
}
