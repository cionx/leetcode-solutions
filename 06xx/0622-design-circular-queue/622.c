/* 622. Design Circular Queue */

/* Complexities are given per operation. */

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int *entries;
	int front;
	int rear;
	int size;
	int maxSize;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue *queue, int value);
bool myCircularQueueDeQueue(MyCircularQueue *queue);
int myCircularQueueFront(MyCircularQueue *queue);
int myCircularQueueRear(MyCircularQueue *queue);
bool myCircularQueueIsEmpty(MyCircularQueue *queue);
bool myCircularQueueIsFull(MyCircularQueue *queue);
void myCircularQueueFree(MyCircularQueue *queue);

/* Time: Θ(1)
 * Space: Θ(1) */
MyCircularQueue *myCircularQueueCreate(int k)
{
	if (k < 0)
		return NULL;
	MyCircularQueue *queue = malloc(sizeof(MyCircularQueue));
	queue->entries = malloc((size_t) k * sizeof(int));
	queue->front = 0;
	queue->rear = -1;
	queue->size = 0;
	queue->maxSize = k;
	return queue;
}

/* Time: Θ(1)
 * Space: Θ(1) */
bool myCircularQueueEnQueue(MyCircularQueue *queue, int value)
{
	if (myCircularQueueIsFull(queue))
		return false;
	queue->rear = (queue->rear + 1) % queue->maxSize;
	queue->entries[queue->rear] = value;
	++queue->size;
	return true;
}

/* Time: Θ(1)
 * Space: Θ(1) */
bool myCircularQueueDeQueue(MyCircularQueue *queue)
{
	if (myCircularQueueIsEmpty(queue))
		return false;
	queue->front = (queue->front + 1) % queue->maxSize;
	--queue->size;
	return true;
}

/* Time: Θ(1)
 * Space: Θ(1) */
int myCircularQueueFront(MyCircularQueue *queue)
{
	if (myCircularQueueIsEmpty(queue))
		return -1;
	return queue->entries[queue->front];
}

/* Time: Θ(1)
 * Space: Θ(1) */
int myCircularQueueRear(MyCircularQueue *queue)
{
	if (myCircularQueueIsEmpty(queue))
		return -1;
	return queue->entries[queue->rear];
}

/* Time: Θ(1)
 * Space: Θ(1) */
bool myCircularQueueIsEmpty(MyCircularQueue *queue)
{
	return queue->size == 0;
}

/* Time: Θ(1)
 * Space: Θ(1) */
bool myCircularQueueIsFull(MyCircularQueue *queue)
{
	return queue->size == queue->maxSize;
}

/* Time: Θ(1)
 * Space: Θ(1) */
void myCircularQueueFree(MyCircularQueue *queue)
{
	free(queue->entries);
	free(queue);
}
