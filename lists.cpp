#include "lists.h"

List init(Book book) {
    Node* root = (Node*) malloc(sizeof(Node));
    root->data = book;
    root->next = NULL; // следующий элемент списка
    return List { .first = root };  
}

Node* addBook(Node* elem, Book book) {
    Node* temp = (Node*) malloc(sizeof(Node));
    Node* p = elem->next;           // сохранение указателя на следующий узел
    elem->next = temp;              // предыдущий узел указывает на создаваемый
    temp->data = book;              // сохранение поля данных добавляемого узла
    temp->next = p;                 // созданный узел указывает на следующий элемент
    return temp;                    // возвращаем адрес добавленного узла
}

void deleteBook(List* list, Node* elem) {
    Node* temp = list->first;
    // просматриваем список начиная с корня пока не найдем узел, предшествующий lst
    while (temp->next != elem)
        temp = temp->next;
    temp->next = elem->next;        // переставляем указатель
    free(elem);
}

void printBooks(List* list) {
    Node* p = list->first;
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
