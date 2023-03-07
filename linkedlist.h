#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include "samplestructs.h"

struct LinkedList {
    int size;
    LinkedNode *head;
    LinkedNode *tail;
};

LinkedList initLinkedList();
void disposeList(LinkedList* list);
void pushFront(LinkedList* list, Book data);
Book popFront(LinkedList* list);
void pushBack(LinkedList* list, Book data);
Book popBack(LinkedList* list);

#endif // LINKEDLIST_H
