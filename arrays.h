#ifndef ARRAYS_H
#define ARRAYS_H

#include "samplestructs.h"

// Коллекция на базе статического массива
struct SBookCollection {
    Book books[SIZE];
    int size;
};

void staticAddBook(SBookCollection* const books, Book* book, int index);
void staticRemoveBook(SBookCollection* const books, int index);

struct DBookCollection {
    Book* books;
    int size;
};

void dynamicAddBook(DBookCollection* const books, Book* book, int index);
void dynamicRemoveBook(DBookCollection* const books, int index);

#endif // ARRAYS_H
