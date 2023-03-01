#ifndef STACK_H
#define STACK_H

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
    Book data;
    Node* next;
};

struct Stack {
    Node* top;
};

Stack initStack();
bool isEmpty(Stack* stack);
void push(Stack* stack, Book book);
bool pop(Book* result, Stack* stack);
void clear(Stack* stack);
bool peek(Book* book, Stack* stack);

#endif // STACK_H
