#ifndef LISTS_H
#define LISTS_H

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
    Book data;  // поле данных
    Node* next; // поле связей
};

Node* init(Book book);
Node* addBook(Node* elem, Book book);
Node* deleteBook(Node* elem, Node* root);
void printBooks(Node* list);

#endif // LISTS_H
