#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <cstdio>
#include <stdlib.h>
#include "book.h"

struct QueueNode {
  Book data;
  QueueNode* next;
};

struct Queue {
	QueueNode *head, *tail;
};

Queue initQueue();
bool isEmpty(Queue* queue);
bool pop(Book* book, Queue* queue);
void push(Queue *queue, Book book);

#endif // QUEUE_H
