#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdlib.h>
#include "samplestructs.h"

// Список на базе статического массива
struct SBookList {
    Book books[SIZE];
    int size;
};

void staticAddBook(SBookList* books, Book book, int index);
void staticRemoveBook(SBookList* books, int index);

struct DBookList {
    Book* books;
    int size;
};

void dynamicAddBook(DBookList* books, Book book, int index);
void dynamicRemoveBook(DBookList* books, int index);

#endif // ARRAYS_H
