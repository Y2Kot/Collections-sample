#include "lists.h"

List init(Book book) {
    Node* root = (Node*) malloc(sizeof(Node));
    root->data = book;
    root->next = NULL; // следующий элемент списка
    // Если поддерживается стандарт c++ 20, то можно использовать именованные параметры:
    // return List{ .first = root };
    return List { root };  
}

void pushStart(List* list, Book book) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = book;
    node->next = list->first;

    list->first = node;
}

void pushEnd(List* list, Book book) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = book;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
    } else {
        Node* temp = list->first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

void deleteBook(List* list, Book* elem) {
    Node* temp = list->first;

    if(temp == NULL)
        return;

    if(!strcmp(temp->data.name, elem->name)) {
        list->first = temp->next;
        free(temp);
        return;
    }

    int isRemoved = 0;
    while (temp->next && !isRemoved) {
        if (!strcmp(temp->next->data.name, elem->name)) {
            Node* removing = temp->next;
            temp->next = removing->next;
            free(removing);
            break;
        }
        temp = temp->next;
    }
}

void printBooks(List* list) {
    Node* p = list->first;

    if (p == NULL)
        return;

    do {
        printf("%p ", &(p->data));  // вывод адреса элемента p->data
        p = p->next;                // переход к следующему узлу
    } while (p != NULL);
}

void deleteList(List* list) {
    Node* p = list->first;
    while (p->next) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
    free(list->first);                     // возможно повтороное освобождение памяти
    free(list);
}
