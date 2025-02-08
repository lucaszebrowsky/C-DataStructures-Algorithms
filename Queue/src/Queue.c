#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

bool is_full(queue_t *queue)
{
	if (NULL == queue) {
		return true;
	}

	return (queue->elements == queue->size);
}

bool is_empty(queue_t *queue)
{
	if (NULL == queue) {
		return true;
	}

	return (queue->elements == 0);
}

queue_t *init_queue(size_t size)
{
	if (0 == size) {
		return NULL;
	}

	queue_t *q = malloc(sizeof(queue_t));

	if (NULL != q) {
		q->size = size;
		q->elements = 0;
		q->head = 0;
		q->tail = 0;
		q->values = malloc(sizeof(int) * size);

		if (NULL == q->values) {
			free(q);
			q = NULL;
		}
	}

	return q;
}

bool enqueue(queue_t *queue, int value)
{
	if (is_full(queue)) {
		return false;
	}

	queue->values[queue->tail] = value;
	queue->tail = (queue->tail + 1) % queue->size;
	queue->elements++;

	return true;
}

int dequeue(queue_t *queue)
{
	if (is_empty(queue)) {
		return QUEUE_EMPTY;
	}

	int result = queue->values[queue->head];

	queue->head = (queue->head + 1) % queue->size;
	queue->elements--;

	return result;
}

void queue_destroy(queue_t *queue)
{
	if (queue != NULL && queue->values != NULL) {
		free(queue->values);
		free(queue);
	}
}
