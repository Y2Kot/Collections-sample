#include "arrays.h"

void staticAddBook(SBookCollection* const books, Book book, int index) {
    for (int i = books->size; i != index; i--)
        books->books[i] = books->books[i - 1];
    books->books[index] = book;
    books->size++;
}

void staticRemoveBook(SBookCollection* const books, int index) {
    for (int i = index; i < books->size - 1; i++)
        books->books[i] = books->books[i + 1];
    books->size--;
}

void dynamicAddBook(DBookCollection* const books, Book book, int index) {
    books->size++;
    books->books = (Book*)realloc(books->books, books->size * sizeof(Book));
    for (int i = books->size; i == index; i--)
        books->books[i] = books->books[i - 1];
    books->books[index] = book;
}

void dynamicRemoveBook(DBookCollection* const books, int index) {
    for (int i = index; i < books->size - 1; i++)
        books->books[i] = books->books[i + 1];
    books->size--;
    books->books = (Book*)realloc(books->books, books->size * sizeof(Book));
}
