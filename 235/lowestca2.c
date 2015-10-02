#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  int min = p->val;
  int max = q->val;
  if (min > max) {
    int tmp = max;
    max = min;
    min = tmp;
  }
  int value = root->val;
  if (value >= min && value <= max) {
    return root;
  }
  struct TreeNode* left = root->left;
  struct TreeNode* right = root->right;
  if (left == NULL || right == NULL) {
    return root;
  }
  if (value > max) {
    return lowestCommonAncestor(left, p, q);
  }
  if (value < max) {
    return lowestCommonAncestor(right, p, q);
  }
  return NULL;
}
