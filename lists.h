#ifndef LISTS_H
#define LISTS_H

#include <cstdio>
#include <stdlib.h>
#include "samplestructs.h"

Node* init(Book book);
Node* addBook(Node* elem, Book book);
Node* deleteBook(Node* elem, Node* root);
void printBooks(Node* list);

#endif // LISTS_H
