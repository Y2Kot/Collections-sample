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
void push(Stack* stack, Book* book);
bool pop(Stack* stack, Book** result);
void clear(Stack* stack);
bool peek(Stack* stack, Book** book);

#endif // STACK_H
