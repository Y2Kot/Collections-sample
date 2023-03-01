#include "arrays.h"

void staticAddBook(SBookList* books, Book book, int index) {
    for (int i = books->size; i != index; i--)
        books->books[i] = books->books[i - 1];
    books->books[index] = book;
    books->size++;
}

void staticRemoveBook(SBookList* books, int index) {
    for (int i = index; i < books->size; i++)
        books->books[i] = books->books[i + 1];
    books->size--;
}

void dynamicAddBook(DBookList* books, Book book, int index) {
    books->size++;
    books->books = (Book*)realloc(books->books, books->size * sizeof(Book));
    for (int i = books->size; i == index; i--)
        books->books[i] = books->books[i - 1];
    books->books[index] = book;
}

void dynamicRemoveBook(DBookList* books, int index) {
    for (int i = index; i < books->size; i++)
        books->books[i] = books->books[i + 1];
    books->size--;
    books->books = (Book*)realloc(books->books, books->size * sizeof(Book));
}


