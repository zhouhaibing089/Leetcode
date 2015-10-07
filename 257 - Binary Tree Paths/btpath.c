#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  struct node*    prev;
  struct node*    next;
  char*           value;
} node;

typedef struct meta {
  node*   head;
  node*   last;
} meta;

typedef meta* list;

// create list
list create_list() {
  list l = (meta*)malloc(sizeof(meta));
  l->head = NULL;
  l->last = NULL;
  return l;
}

// free it
void free_list(list l) {
  node* n = l->head;
  while(n != NULL) {
    node* next = n->next;
    free(n);
    n = next;
  }
  free(l);
}

// add element
void append(list l, char* value) {
  node* n = (node*)malloc(sizeof(node));
  n->value = value;
  n->next = NULL;
  if (l->last == NULL) {
    n->prev = NULL;
    l->last = n;
    l->head = n;
  } else {
    n->prev = l->last;
    l->last->next = n;
    l->last = n;
  }
}

void print_list(list l) {
  node* n = l->head;
  while(n != NULL) {
    printf("%s ", n->value);
    n = n->next;
  }
  printf("\n");
}

char** convert(list l, int size) {
  char** result = (char**)malloc(size * sizeof(char*));
  int i = 0;
  node* n = l->head;
  while (n != NULL) {
    result[i++] = n->value;
    n = n->next;
  }
  return result;
}

char* concat(char* l, char* r) {
  int ll = strlen(l);
  int lr = strlen(r);
  int len = ll + lr + 3;
  char* s = (char*)malloc(sizeof(char) * len);
  s[len - 1] = 0;
  strncpy(s, l, ll);
  s[ll] = '-';
  s[ll + 1] = '>';
  strncpy(s + ll + 2, r, lr);
  return s;
}

typedef struct TreeNode TreeNode;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
  // #1 empty tree
  if (root == NULL) {
    *returnSize = 0;
    return NULL;
  }
  // allocate the value string buffer
  char* v = (char*)malloc(11 * sizeof(char));
  sprintf(v, "%d", root->val);
  // allocate a dynamic length list
  list l = create_list();
  // total size
  int size = 0;
  // #2 concat the value with left tree
  if (root->left != NULL) {
    int count;
    char** sl = binaryTreePaths(root->left, &count);
    size += count;
    if (count > 0) {
      for (int i = 0; i < count; ++i) {
        char* s = concat(v, sl[i]);
        append(l, s);
        free(sl[i]);
      }
      free(sl);
    }
  }
  // #3 concat the value with right tree
  if (root->right != NULL) {
    int count;
    char** sr = binaryTreePaths(root->right, &count);
    size += count;
    if (count > 0) {
      for (int i = 0; i < count; ++i) {
        char* s = concat(v, sr[i]);
        append(l, s);
        free(sr[i]);
      }
      free(sr);
    }
  }
  // return itself
  if (size == 0) {
    *returnSize = 1;
    char** sa = (char**)malloc(sizeof(char*));
    sa[0] = v;
    return sa;
  }
  free(v);
  // convert the list to string array
  *returnSize = size;
  char** result = convert(l, size);
  free_list(l);
  return result;
}

int main() {
  return 0;
}
