/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int left_level(struct TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  return 1 + left_level(root->left);
}

int right_level(struct TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  return 1 + right_level(root->right);
}

int countNodes2(struct TreeNode* root, int ll, int rl) {
  if (root == NULL) {
    return 0;
  }
  if (ll == -1) {
    ll = left_level(root);
  }
  if (rl == -1) {
    rl = right_level(root);
  }
  /* full */
  if (ll == rl) {
    int val = (2 << (ll - 1)) - 1;
    return val;
  }
  int rtl = right_level(root->left);
  if (ll == (rtl + 1)) {
    /* recursion to right */
    int val = countNodes2(root->right, -1, rl - 1);
    return val + (2 << (ll - 2));
  } else {
    /* recursion to left */
    int val = countNodes2(root->left, ll - 1, rtl);
    return val + (2 << (rl - 2));
  }
}

int countNodes(struct TreeNode* root) {
  return countNodes2(root, -1, -1);
}
