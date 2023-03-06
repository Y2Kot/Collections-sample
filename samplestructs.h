#pragma once

const int SIZE = 20;

struct Book {
    char* name;
    char* author;
    int pageCount;
    double rating;
};

struct LinkedListNode {
    Book data;
    LinkedListNode* next;
    LinkedListNode* prev;
};

struct Node {
    Book data;  // поле данных
    Node* next; // поле связей
};
