#ifndef SAMPLESTRUCTS_H
#define SAMPLESTRUCTS_H

const int SIZE = 20;

struct Book {
    char name[SIZE];
    char author[SIZE];
    int pageCount;
    double rating;
};

struct LinkedNode {
    Book* data;         // поле данных
    LinkedNode* next;   // поле связей (предыдущий элемент)
    LinkedNode* prev;   // поле связей (следующий элемент)
};

struct Node {
    Book* data;         // поле данных
    Node* next;         // поле связей
};

#endif // SAMPLESTRUCTS_H
