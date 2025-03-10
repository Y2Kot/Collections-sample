#include "queue.h"
#include <stdlib.h>

Queue initQueue() {
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    return queue;
}

bool isEmpty(Queue* queue) {
    return !queue->head;
}

bool pop(Queue* queue, Book* book) {
    if(isEmpty(queue))
        return false;

    Node* node = queue->head;
    *book = node->data;

    queue->head = node->next;

    free(node);

    return true;

}

void push(Queue *queue, Book* book) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = *book;
    node->next = NULL;

    if(isEmpty(queue))
        queue->head = queue->tail = node;
    else
        queue->tail->next = node;

    queue->tail = node;
}

