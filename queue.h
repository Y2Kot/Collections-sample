#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <cstdio>
#include <stdlib.h>

const int SIZE = 20;

struct Book {
    char name[SIZE];
    char author[SIZE];
    int pageCount;
    float rating;
};

struct Node {
  Book data;
  Node* next;
};

struct Queue {
  Node *head, *tail;
};

Queue initQueue();
bool isEmpty(Queue* queue);
bool pop(Book* book, Queue* queue);
void push(Queue *queue, Book book);

#endif // QUEUE_H
