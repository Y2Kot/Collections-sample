#ifndef LISTS_H
#define LISTS_H

#include <cstdio>
#include <stdlib.h>
#include "samplestructs.h"

struct List {
	Node* first;
};

List init(Book book);
Node* addBook(Node* elem, Book book);
void deleteBook(List* list, Node* elem);
void deleteAllBooks(Node* root);

void push(List* list, Book book);
#endif // LISTS_H
