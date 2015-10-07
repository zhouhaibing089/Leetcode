#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void print_list(struct ListNode* node) {
  printf("[");
  while (node != NULL) {
    printf("%d ", node->val);
    node = node->next;
  }
  printf("]\n");
}

/* reverse the given list */
void reverse(struct ListNode* node, struct ListNode* tail) {
  if (node == NULL) {
    return;
  }
  if (node->next == NULL) {
    node->next = tail;
    return;
  }
  struct ListNode* next = node->next;
  struct ListNode* next_next = next->next;
  node->next = tail;
  next->next = node;
  reverse(next_next, next);
}

bool isPalindrome(struct ListNode* head) {
  /* empty list or single list return true */
  if (head == NULL || head->next == NULL) {
    return true;
  }
  int length = 0;
  struct ListNode* tail = head;
  while(true) {
    ++length;
    if (tail->next == NULL) {
      break;
    }
    tail = tail->next;
  }
  // ====== DEBUG ======
  printf("length=%d\n", length);
  // ======  END  ======
  /* find the middle node */
  int middle = length / 2;
  if (length % 2 != 0) {
    ++middle;
  }
  int i = 0;
  struct ListNode* node = head;
  while (i++ < middle) {
    node = node->next;
  }
  // ====== DEBUG ======
  printf("middle=%d, value=%d\n", middle, node->val);
  // ======  END  ======
  /* reverse it from the middle */
  reverse(node, NULL);
  // ====== DEBUG ======
  print_list(tail);
  // ======  END  ======
  /* compare each */
  while (head != NULL && tail != NULL) {
    // ====== DEBUG ======
    printf("Compare %d %d\n", head->val, tail->val);
    // ======  END  ======
    if (head->val != tail->val) {
      return false;
    }
    head = head->next;
    tail = tail->next;
  }
  return true;
}

int main() {
  struct ListNode* one = (struct ListNode*)malloc(sizeof(struct ListNode));
  one->val = 1;
  struct ListNode* two = (struct ListNode*)malloc(sizeof(struct ListNode));
  two->val = 0;
  struct ListNode* three = (struct ListNode*)malloc(sizeof(struct ListNode));
  three->val = 3;
  struct ListNode* four = (struct ListNode*)malloc(sizeof(struct ListNode));
  four->val = 4;
  struct ListNode* five = (struct ListNode*)malloc(sizeof(struct ListNode));
  five->val = 0;
  struct ListNode* six = (struct ListNode*)malloc(sizeof(struct ListNode));
  six->val = 1;
  one->next = two;
  two->next = three;
  three->next = four;
  four->next = five;
  five->next = six;
  six->next = NULL;
  printf("result=%d\n", isPalindrome(one));
  return 0;
}
