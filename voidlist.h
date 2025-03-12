#ifndef VOIDLIST_H
#define VOIDLIST_H

#include <stdlib.h>

#define MAX_NAME 255

typedef struct Node Node;

typedef struct Student {
    unsigned char age;
    unsigned char weight;
    char name[MAX_NAME];
} Student;

typedef struct VoidList {
    Node* root;
    size_t data_size;
} VoidList;

void init_list(VoidList* list, size_t data_size);

void free_list(VoidList* list);

bool push_front(VoidList* list, const void* data);

bool pop_front(VoidList* list, void* data);

#endif // VOIDLIST_H
