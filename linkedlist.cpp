#include "linkedlist.h"
#include <stdlib.h>

LinkedList* initLinkedList() {
    LinkedList* lst = (LinkedList*)malloc(sizeof(LinkedList));

    lst->size = 0;
    lst->head = NULL;
    lst->tail = NULL;

    return lst;
}

void disposeList(LinkedList* list) {
    LinkedNode* tmp = list->head;
    LinkedNode* next = NULL;

    while (tmp) {
        next = tmp->prev;
        free(tmp);
        tmp = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    free(list);
}

void pushFront(LinkedList* list, Book* data) {
    LinkedNode* tmp = (LinkedNode*)malloc(sizeof(LinkedNode));

    tmp->data = *data;
    tmp->next = list->head;
    tmp->prev = NULL;

    if (list->head)
        list->head->prev = tmp;

    list->head = tmp;

    if (list->tail == NULL)
        list->tail = tmp;

    list->size++;
}

void pushBack(LinkedList* list, Book* data) {
    LinkedNode* tmp = (LinkedNode*)malloc(sizeof(LinkedNode));

    tmp->data = *data;
    tmp->prev = list->tail;
    tmp->next = NULL;
    if (list->tail)
        list->tail->next = tmp;

    list->tail = tmp;

    if (list->head == NULL)
        list->head = tmp;

    list->size++;
}

bool popFront(LinkedList* list, Book* book) {
    LinkedNode* oldHead = list->head;

    if(oldHead == NULL)
        return false;

    list->head = oldHead->next;

    if (list->head)
        list->head->prev = NULL;

    if (oldHead == list->tail)
        list->tail = NULL;

    if(book != NULL)
        *book = oldHead->data;

    free(oldHead);

    list->size--;
    return true;
}

bool popBack(LinkedList* list, Book* book) {
    LinkedNode* oldTail = list->tail;

    if(oldTail == NULL)
        return false;

    list->tail = oldTail->prev;
    if (list->tail)
        list->tail->next = NULL;

    if (oldTail == list->head)
        list->head = NULL;

    if (book != NULL)
        *book = oldTail->data;

    free(oldTail);

    list->size--;
    return true;
}
