#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <cstdio>
#include <stdlib.h>
#include "samplestructs.h"

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
