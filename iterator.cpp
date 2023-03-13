#include "iterator.h"

Iterator begin(const List& list) {
    Iterator iterator;
    iterator.current = list.first;
//     Опционально можно написать так:
//    Iterator iterator = { list.first };
//      Или даже так:
//    Iterator iterator = { .current = list.first };
    return iterator;
}

Iterator end(const List& list) {
    Iterator iterator = { list.first };
    while(iterator.current->next != NULL) {
        iterator.current = iterator.current->next;
    }
    return iterator;
}

bool next(Iterator& it) {
    return it.current ? (it.current = it.current->next, true) : false;
}

Book* get(Iterator& it) {
    return it.current ? &(it.current->data) : NULL;
}

Book* getNext(Iterator& it) {
    return (it.current && it.current->next) ? &(it.current->next->data) : NULL;
}

bool set(Iterator& it, Book book) {
    if (!it.current)
        return false;

    it.current->data = book;
    return true;
}

bool setNext (Iterator& it, Book book) {
    if (!it.current || !it.current->next)
        return false;

    it.current->next->data = book;
    return true;
}

bool isSet(const Iterator& it) {
    return it.current;
}

bool add(List& list, Iterator& it, Book book) {
    if (!isSet(it))
        return false;

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = book;

    if (!list.first) {
        node->next = NULL;
        list.first = it.current = node;
    } else if (!it.current->next) {
        node->next = NULL;
        it.current->next = node;
    } else {
        node->next = it.current->next;
        it.current->next = node;
    }

    return true;

}

bool remove(Book& book, List& list, const Iterator& it) {
    if (!list.first || !isSet(it) || !it.current->next)
        return false;

    Node* delNode = it.current->next;
    book = delNode->data;

    it.current->next = delNode->next;

    free(delNode);
    return true;
}

bool operator == (const Iterator& it1, const Iterator& it2) {
    return it1.current == it2.current;
}

bool operator != (const Iterator& it1, const Iterator& it2) {
    return it1.current != it2.current;
}
