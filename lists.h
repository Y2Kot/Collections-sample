#ifndef LISTS_H
#define LISTS_H

#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include "samplestructs.h"

struct List {
	Node* first;
};

List init(Book book);
void addBook(List* elem, Book book);
void deleteBookByName(List* list, const char* name);
void clear(List* list);

void pushStart(List* list, Book book);
void pushEnd(List* list, Book book);
void handleBooks(List* list, void(*handler)(Book*));
#endif // LISTS_H
