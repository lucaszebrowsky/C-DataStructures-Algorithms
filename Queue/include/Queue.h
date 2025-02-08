#pragma once
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY -1

typedef struct queue {
	int *values;
	int head;
	int tail;
	size_t size; // max size of the internal array
	size_t elements; // number of elements
} queue_t;

bool enqueue(queue_t *queue, int value);
int dequeue(queue_t *queue);

queue_t *init_queue(size_t size);
void queue_destroy(queue_t *queue);

bool is_empty(queue_t *queue);
bool is_full(queue_t *queue);
