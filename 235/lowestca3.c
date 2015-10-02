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
  while (root->val < min || root->val > max) {
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    if (left == NULL || right == NULL) {
      break;
    }
    if (root->val < min) {
      root = root->right;
    }
    if (root->val > max) {
      root = root->left;
    }
  }
  return root;
}
