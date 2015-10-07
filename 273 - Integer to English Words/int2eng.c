#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// concatenate two strings, no free action here
char* concat(char* s1, char* s2) {
  // allocate the char array
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int len = len1 + 1 + len2 + 1;
  if (len1 == 0 || len2 == 0) {
    len -= 1;
  }
  char* s = (char*)malloc(sizeof(char) * len);
  s[len - 1] = 0;
  // do the copy
  strncpy(s, s1, len1);
  if (len1 != 0 && len2 != 0) {
    s[len1] = ' ';
  }
  strncpy(s + (len1 == 0 || len2 == 0 ? 0 : len1 + 1), s2, len2);
  return s;
}

// for those number which is less than one thousand
char* simpleNumToWords(int num) {
  // #1: 1 <= i <= 20 => A[i]
  // #2: 30 <= i <= 90 => A[21 + (i - 30) / 10]
  static char* dict[] = {
    "",         // 0
    "One",      // 1
    "Two",      // 2
    "Three",    // 3
    "Four",     // 4
    "Five",     // 5
    "Six",      // 6
    "Seven",    // 7
    "Eight",    // 8
    "Nine",     // 9
    "Ten",      // 10
    "Eleven",   // 11
    "Twelve",   // 12
    "Thirteen", // 13
    "Fourteen", // 14
    "Fifteen",  // 15
    "Sixteen",  // 16
    "Seventeen",// 17
    "Eighteen", // 18
    "Nineteen", // 19
    "Twenty",   // 20
    "Thirty",   // 21
    "Forty",    // 22
    "Fifty",    // 23
    "Sixty",    // 24
    "Seventy",  // 25
    "Eighty",   // 26
    "Ninety"    // 27
  };

  // initialize a zero-length string
  char* r = (char*)malloc(sizeof(char));
  r[0] = 0;
  // h will range from 0-9
  int h = num / 100;
  if (h != 0) {
    r = concat(dict[h], "Hundred");
  }
  num %= 100;
  int t = num / 10;
  if (t >= 2) {
    char* tmp = r;
    r = concat(tmp, dict[20 + t - 2]);
    num -= t * 10;
    free(tmp);
  }
  char* tmp = r;
  r = concat(tmp, dict[num]);
  free(tmp);
  return r;
}

char* numberToWords(int num) {
  if (num == 0) {
    return "Zero";
  }
  // initialize a zero-length string
  char* r = (char*)malloc(sizeof(char));
  r[0] = 0;
  // billion
  int b = num / 1000000000;
  if (b > 0) {
    char* tmp = r;
    char* tmp2 = simpleNumToWords(b);
    r = concat(tmp, tmp2);
    free(tmp);
    free(tmp2);
    tmp = r;
    r = concat(tmp, "Billion");
    free(tmp);
  }
  printf("r=%s\n", r);
  num %= 1000000000;
  // milliion
  int m = num / 1000000;
  if (m > 0) {
    char* tmp = r;
    char* tmp2 = simpleNumToWords(m);
    r = concat(tmp, tmp2);
    free(tmp);
    free(tmp2);
    tmp = r;
    r = concat(tmp, "Million");
    free(tmp);
  }
  printf("r=%s\n", r);
  num %= 1000000;
  int t = num / 1000;
  // thousand
  if (t > 0) {
    char* tmp = r;
    char* tmp2 = simpleNumToWords(t);
    r = concat(tmp, tmp2);
    free(tmp);
    free(tmp2);
    tmp = r;
    r = concat(tmp, "Thousand");
    free(tmp);
  }
  printf("r=%s\n", r);
  // less than one thousand
  num %= 1000;
  char* tmp = r;
  char* tmp2 = simpleNumToWords(num);
  r = concat(tmp, tmp2);
  free(tmp);
  free(tmp2);
  return r;
}

int main() {
    char* s = numberToWords(123456);
    printf("%d=%s\n", 123456, s);
    free(s);
    return 0;
}
