#include <stdio.h>
#include "Queue.h"

int main(void)
{
	queue_t *q = init_queue(3);

	if (NULL == q) {
		printf("Failed to create a queue!\n");
		return EXIT_FAILURE;
	}

	enqueue(q, 11);
	enqueue(q, 34);
	enqueue(q, 99);
	// This one should not be added as the queue is full
	enqueue(q, 4);

	int value;
	while ((value = dequeue(q)) != QUEUE_EMPTY) {
		printf("value = %d\n", value);
	}

	queue_destroy(q);
	return EXIT_SUCCESS;
}
