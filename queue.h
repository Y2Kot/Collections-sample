#ifndef QUEUE_H
#define QUEUE_H

#include "samplestructs.h"

struct Queue {
	Node *head, *tail;
};

Queue initQueue();
bool isEmpty(Queue* queue);
bool pop(Queue* queue, Book* book);
void push(Queue *queue, Book* book);

#endif // QUEUE_H
