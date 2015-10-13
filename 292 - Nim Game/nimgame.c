#include <stdbool.h>

/*
 * if n <= 3, first one wins
 * if n = 4, the second one wins
 */
bool canWinNim(int n) {
  return n % 4;
}
