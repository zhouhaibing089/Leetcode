#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char** letterCombinations(char* digits, int* returnSize) {
  char* dict[10] = {
    NULL, NULL, "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
  };
  int length = strlen(digits);
  /* empty input */
  if (length == 0) {
    *returnSize = 0;
    return NULL;
  }
  int count = 1;
  for (int i = 0; i < length; ++i) {
    int n = digits[i] - '0';
    /* consider 0 and 1 as illegal input */
    if (n == 0 || n == 1) {
      count = 0;
      break;
    }
    count *= strlen(dict[n]);
  }
  *returnSize = count;
  if (count == 0) {
    return NULL;
  }
  /* memory allocate */
  char** r = (char**)malloc(sizeof(char*) * count);
  /* each string is exactly length characters */
  for (int i = 0; i < count; ++i) {
    r[i] = (char*)malloc(sizeof(char) * (length + 1));
    r[i][length] = 0;
  }
  /* for each digit */
  int step = count;
  for (int i = 0; i < length; ++i) {
    int l = strlen(dict[digits[i] - '0']);
    step /= l;
    /* every digits appear step times */
    int n = 0;
    int p = 0;
    for (int j = 0; j < count; ++j) {
      r[j][i] = dict[digits[i] - '0'][p];
      ++n;
      if (n == step) {
        p = (p + 1) % l;
        n = 0;
      }
    }
  }
  return r;
}

int main(int argc, char** argv) {
  int size;
  char** r = letterCombinations(argv[1], &size);
  for (int i = 0; i < size; ++i) {
    printf("%s\n", r[i]);
  }
  return 0;
}
