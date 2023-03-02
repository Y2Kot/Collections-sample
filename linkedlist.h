#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <cstdio>
#include <stdlib.h>
#include "book.h"

struct LinkedListNode {
    Book data;
    LinkedListNode *next;
    LinkedListNode *prev;
};

struct LinkedList {
    int size;
    LinkedListNode *head;
    LinkedListNode *tail;
};

LinkedList initLinkedList();
void disposeList(LinkedList* list);
void pushFront(LinkedList* list, Book data);
Book popFront(LinkedList* list);
void pushBack(LinkedList* list, Book data);
Book popBack(LinkedList* list);


#endif // LINKEDLIST_H
