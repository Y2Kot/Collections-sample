#pragma once

const int SIZE = 20;

struct Book {
    char* name;
    char* author;
    int pageCount;
    double rating;
};

struct LinkedNode {
    Book data;
    LinkedNode* next;
    LinkedNode* prev;
};

struct Node {
    Book data;  // ���� ������
    Node* next; // ���� ������
};
