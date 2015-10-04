/* definition of queue */
typedef struct {
  int* store;
  int start;
  int end;
  int size;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
  queue->start = 0;
  queue->end = -1;
  queue->size = maxSize;
  queue->store = (int*)malloc(sizeof(int) * maxSize);
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
  queue->end = (queue->end + 1) % (queue->size);
  queue->store[queue->end] = element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
  queue->start = (queue->start + 1) % (queue->size);
}

/* Get the front element */
int queuePeek(Queue *queue) {
  return queue->store[queue->start];
}

/* Return the size of queue */
int queueSize(Queue* queue) {
  return (queue->end + 1) % (queue->size) - queue->start;
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
  return queueSize(queue) == 0;;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
  free(queue->store);
}

typedef struct {
  Queue* queue_ptr;
  int size;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
  stack->size = maxSize;
  stack->queue_ptr = (Queue*)malloc(sizeof(Queue));
  queueCreate(stack->queue_ptr, maxSize);
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
  queuePush(stack->queue_ptr, element);
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
  Queue* newqueue_ptr = (Queue*)malloc(sizeof(Queue));
  queueCreate(newqueue_ptr, stack->size);
  while (queueSize(stack->queue_ptr) != 1) {
    queuePush(newqueue_ptr, queuePeek(stack->queue_ptr));
    queuePop(stack->queue_ptr);
  }
  queueDestroy(stack->queue_ptr);
  stack->queue_ptr = newqueue_ptr;
}

/* Get the top element */
int stackTop(Stack *stack) {
  Queue* newqueue_ptr = (Queue*)malloc(sizeof(Queue));
  queueCreate(newqueue_ptr, stack->size);
  while (queueSize(stack->queue_ptr) != 1) {
    queuePush(newqueue_ptr, queuePeek(stack->queue_ptr));
    queuePop(stack->queue_ptr);
  }
  int val = queuePeek(stack->queue_ptr);
  queueDestroy(stack->queue_ptr);
  queuePush(newqueue_ptr, val);
  stack->queue_ptr = newqueue_ptr;
  return val;
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
  return queueEmpty(stack->queue_ptr);
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
  queueDestroy(stack->queue_ptr);
}
