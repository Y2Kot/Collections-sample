#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdlib.h>

const int SIZE = 20;

struct Book {
    char name[SIZE];
    char author[SIZE];
    int pageCount;
    float rating;
};

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


#endif // ARRAYS_H
