#include "stack.h"
#include <stdlib.h>

Stack initStack() {
    Stack stack = { NULL };
    return stack;
}

bool isEmpty(Stack* stack) {
    return !stack->top;
}

void push(Stack* stack, Book* book) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = *book;
    newNode->next = stack->top;
    stack->top = newNode;
}

bool pop(Stack* stack, Book* book) {
    if (isEmpty(stack))
        return false;

    Node* node = stack->top;
    stack->top = stack->top->next;
    *book = node->data;
    free(node);
    return true;
}

void clear(Stack* stack) {
    while (stack->top) {
        Node* tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
}

bool peek(Stack* stack, Book* book) {
    if (isEmpty(stack))
        return false;

    *book = stack->top->data;
    return true;
}
