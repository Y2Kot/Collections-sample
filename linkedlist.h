#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
    Node *next;
    Node *prev;
};

struct LinkedList {
    int size;
    Node *head;
    Node *tail;
};

LinkedList initLinkedList();
void disposeList(LinkedList* list);
void pushFront(LinkedList* list, Book data);
Book popFront(LinkedList* list);
void pushBack(LinkedList* list, Book data);
Book popBack(LinkedList* list);


#endif // LINKEDLIST_H
