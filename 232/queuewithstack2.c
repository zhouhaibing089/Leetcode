#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Stack {
  int* store;
  int p;
} Stack;

/* create stack with max size */
Stack* stack(int maxSize) {
  Stack* stk_ptr = (Stack*)malloc(sizeof(Stack));
  stk_ptr->store = (int*)malloc(maxSize * sizeof(int));
  stk_ptr->p = -1;
  return stk_ptr;
}

/* push one element */
void push(Stack* stk_ptr, int element) {
  stk_ptr->store[++(stk_ptr->p)] = element;
}

/* pop one element out */
void pop(Stack* stk_ptr) {
  --(stk_ptr->p);
}

/* get the element at top */
int peek(Stack* stk_ptr) {
  return stk_ptr->store[stk_ptr->p];
}

/* how many element in the stack */
int size(Stack* stk_ptr) {
  return stk_ptr->p + 1;
}

/* is the stack empty */
bool is_empty(Stack* stk_ptr) {
  return size(stk_ptr) == 0;
}

/* free the allocated memory */
void stack_free(Stack* stk_ptr) {
  free(stk_ptr->store);
  free(stk_ptr);
}

typedef struct {
  Stack* stk_ptr;
  int size;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
  queue->stk_ptr = stack(maxSize);
  queue->size = maxSize;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
  push(queue->stk_ptr, element);
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
  Stack* tmp_ptr = stack(queue->size);
  while(size(queue->stk_ptr) > 1) {
    push(tmp_ptr, peek(queue->stk_ptr));
    pop(queue->stk_ptr);
  }
  stack_free(queue->stk_ptr);
  Stack* tmp_ptr2 = stack(queue->size);
  while(!is_empty(tmp_ptr)) {
    push(tmp_ptr2, peek(tmp_ptr));
    pop(tmp_ptr);
  }
  stack_free(tmp_ptr);
  queue->stk_ptr = tmp_ptr2;
}

/* Get the front element */
int queuePeek(Queue *queue) {
  Stack* tmp_ptr = stack(queue->size);
  while(size(queue->stk_ptr) > 1) {
    push(tmp_ptr, peek(queue->stk_ptr));
    pop(queue->stk_ptr);
  }
  int value = peek(queue->stk_ptr);
  while(!is_empty(tmp_ptr)) {
    push(queue->stk_ptr, peek(tmp_ptr));
    pop(tmp_ptr);
  }
  stack_free(tmp_ptr);
  return value;
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
  return is_empty(queue->stk_ptr);
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
  stack_free(queue->stk_ptr);
}
