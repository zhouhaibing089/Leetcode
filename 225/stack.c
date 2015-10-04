typedef struct {
  int* store;
  int p;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
  stack->store = (int*)malloc(sizeof(int) * maxSize);
  stack->p = -1;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
  ++(stack->p);
  stack->store[stack->p] = element;
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
  --(stack->p);
}

/* Get the top element */
int stackTop(Stack *stack) {
  return stack->store[stack->p];
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
  return stack->p == -1;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
  free(stack->store);
}
