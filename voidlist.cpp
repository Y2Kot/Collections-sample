#include "voidlist.h"
#include <string.h>

typedef struct Node
{
    void* data;
    struct Node* next;
} Node;

// Инкапсулирована внутри файла реализации
Node* allocate_node(const void* data, size_t size)
{
    Node* node = (Node*)malloc(sizeof(Node) + size);
    if (node != NULL)
    {
        node->data = (void*)((char*)node + sizeof(Node));
        node->next = NULL;

        memcpy(node->data, data, size);
    }

    return node;
}

void free_node(Node* node)
{
    node->next = NULL;
    free(node);
}

void init_list(VoidList* list, size_t data_size)
{
    list->root = NULL;
    list->data_size = data_size;
}

void free_list(VoidList* list)
{
    Node* current = list->root, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free_node(current);
        current = next;
    }

    list->root = NULL;
    list->data_size = 0;
}

bool push_front(VoidList* list, const void* data)
{
    Node* node = allocate_node(data, list->data_size);
    if (node == NULL)
        return false;

    node->next = list->root;
    list->root = node;
    return true;
}

bool pop_front(VoidList* list, void* data)
{
    Node* node = list->root;
    if (node == NULL)
        return false;

    if (data != NULL)
        memcpy(data, node->data, list->data_size);

    list->root = node->next;
    free(node);
    return true;
}
