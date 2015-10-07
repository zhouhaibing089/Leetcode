#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool compare(char* s, int s1, int e1, int s2, int e2) {
  // printf("Compare s[%d:%d] with s[%d, %d]\n", s1, e1, s2, e2);
  if ((e1 - s1) != (e2 - s2)) {
    return false;
  }
  for (int i = s1; i < e1; ++i) {
    if (s[i] != s[s2 + i - s1]) {
      // printf("Not Equal: s[%d] != s[%d]\n", i, s2 + i - s1);
      return false;
    }
  }
  return true;
}

bool wordPattern(char* pattern, char* str) {
  int pl = strlen(pattern);
  /* string processing */
  int* tbl = (int*)malloc(sizeof(int) * (pl + 1));
  tbl[0] = 0;
  /* find all the space position */
  int i = 0;
  int index = 1;
  while (true) {
    char c = str[i++];
    if (c == 0) {
      break;
    }
    if (c == ' ') {
      if (index >= pl) {
        return false;
      }
      tbl[index++] = i;
    }
  }
  if (index != pl) {
    return false;
  }
  tbl[pl] = i;
  // ====== DEBUG ======
  // printf("Table: [");
  // for (int i = 0; i <= index; ++i) {
  //   printf("%d ", tbl[i]);
  // }
  // printf("]\n");
  // ======  END  ======
  /* pattern processing */
  int dict[26] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1
  };
  for (int i = 0; i < pl; ++i) {
    char pc = pattern[i];
    if (dict[pc - 'a'] == -1) {
      dict[pc - 'a'] = i;
    } else {
      /* compare str[i] and str[dict[pc - 'a']] */
      if (!compare(str, tbl[i], tbl[i + 1] - 1, tbl[dict[pc - 'a']], tbl[dict[pc - 'a'] + 1] - 1)) {
        return false;
      }
    }
  }
  /* difference test */
  for (int i = 0; i < 25; ++i) {
    if (dict[i] == -1) {
      continue;
    }
    for (int j = (i + 1); j < 26; ++j) {
      if (dict[j] == -1) {
        continue;
      }
      if (compare(str, tbl[dict[i]], tbl[dict[i] + 1] - 1, tbl[dict[j]], tbl[dict[j] + 1] - 1)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  printf("%d\n", wordPattern("abba", "dog dog dog dog"));
  return 0;
}
