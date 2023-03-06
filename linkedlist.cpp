#include "linkedlist.h"

LinkedList initLinkedList() {
    LinkedList tmp;
    tmp.size = 0;
    tmp.head = NULL;
    tmp.tail = NULL;

    return tmp;
}

void disposeList(LinkedList* list) {
    LinkedNode* tmp = list->head;
    LinkedNode* next = NULL;
    while (tmp) {
        next = tmp->prev;
        free(tmp);
        tmp = next;
    }
    free(list);
}

void pushFront(LinkedList* list, Book data) {
    LinkedNode* tmp = (LinkedNode*)malloc(sizeof(LinkedNode));

    tmp->data = data;
    tmp->next = list->head;
    tmp->prev = NULL;

    if (list->head)
        list->head->prev = tmp;

    list->head = tmp;

    if (list->tail == NULL)
        list->tail = tmp;

    list->size++;
}

void pushBack(LinkedList* list, Book data) {
    LinkedNode* tmp = (LinkedNode*)malloc(sizeof(LinkedNode));

    tmp->data = data;
    tmp->prev = list->tail;
    tmp->next = NULL;
    if (list->tail)
        list->tail->next = tmp;

    list->tail = tmp;

    if (list->head == NULL)
        list->head = tmp;

    list->size++;
}

Book popFront(LinkedList* list) {
    LinkedNode* oldHead = list->head;
    list->head = oldHead->next;
    if (list->head)
        list->head->prev = NULL;

    if (oldHead == list->tail)
        list->tail = NULL;

    Book book = oldHead->data;
    free(oldHead);

    list->size--;
    return book;
}

Book popBack(LinkedList* list) {
    LinkedNode* oldTail = list->tail;
    list->tail = oldTail->prev;
    if (list->tail)
        list->tail->next = NULL;

    if (oldTail == list->head)
        list->head = NULL;

    Book book = oldTail->data;
    free(oldTail);

    list->size--;
    return book;
}
