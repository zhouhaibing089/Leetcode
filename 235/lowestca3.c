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
  while (value < min || value > max) {
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    if (left == NULL || right == NULL) {
      break;
    }
    if (value < min) {
      root = root->right;
      value = root->val;
    }
    if (value > max) {
      root = root->left;
      value = root->val;
    }
  }
  return root;
}
