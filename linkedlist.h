#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "samplestructs.h"

struct LinkedList {
    int size;
    LinkedNode *head;
    LinkedNode *tail;
};

LinkedList* initLinkedList();
void disposeList(LinkedList* list);
void pushFront(LinkedList* list, Book* data);
bool popFront(LinkedList* list, Book* book);
void pushBack(LinkedList* list, Book* data);
bool popBack(LinkedList* list, Book* book);

#endif // LINKEDLIST_H
