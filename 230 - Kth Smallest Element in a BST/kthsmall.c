

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int kthSmallest2(struct TreeNode* root, int k, int* flag) {
  printf("Inspect %d, k=%d, flag=%d\n", root->val, k, *flag);
  if (root->left != NULL) {
    /* search to left */
    int val = kthSmallest2(root->left, k, flag);
    if (*flag == 0) {
      return val;
    }
  }
  if (k == (*flag + 1)) {
    /* exactly current node */
    *flag = 0;
    return root->val;
  }
  if (root->right != NULL) {
    /* search to right */
    int size = 0;
    int val = kthSmallest2(root->right, k - (*flag) - 1, &size);
    if (size == 0) {
      *flag = 0;
      return val;
    }
    *flag += size;
  }
  /* current node is too small */
  ++(*flag);
}

int kthSmallest(struct TreeNode* root, int k) {
  int size = 0;
  return kthSmallest2(root, k, &size);
}
