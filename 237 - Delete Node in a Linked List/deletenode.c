
struct ListNode {
  int val;
  struct ListNode* next;
};

void deleteNode(struct ListNode* node) {
  struct ListNode* next = node->next;
  node->val = next->val;
  node->next = next->next;
  free(next);
}
