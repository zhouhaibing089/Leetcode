#include <stdlib.h>
#include <stdio.h>

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

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
  return queue->start == (queue->end + 1) % (queue->size);
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
  free(queue->store);
}
