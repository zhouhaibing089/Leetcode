/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

bool is_null(struct TreeNode* root, int val, int level) {
  int mask = 1 << (level - 2);
  for (int i = 0; i < (level - 1); ++i) {
    if ((val & mask) == mask) {
      root = root->right;
    } else {
      root = root->left;
    }
    mask = mask >> 1;
  }
  return root == NULL;
}

int countNodes(struct TreeNode* root) {
  struct TreeNode* p = root;
  int level = 0;
  while (p != NULL) {
    p = p->left;
    ++level;
  }
  if (level == 0) {
    return 0;
  }
  int low = 0;
  int high = 1 << (level - 1);
  /* do the binary search */
  while (low != high) {
    int middle = low + (high - low) / 2;
    // printf("low=%d,high=%d,middle=%d\n", low, high, middle);
    if (is_null(root, middle, level)) {
      /* middle is null */
      if (low == middle) {
        return (1 << (level - 1)) + low - 1;
      }
      high = middle;
    } else {
      /* middle is not null */
      low = middle + 1;
    }
  }
  return (1 << (level - 1)) + low - 1;
}
