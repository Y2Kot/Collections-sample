#ifndef ITERATOR_H
#define ITERATOR_H

#include "samplestructs.h"
#include "lists.h"

struct Iterator {
    Node* current;
};

// установка итератора на первый элемент списка
Iterator begin(const List& list);

// установка итератора на последний элемент списка
Iterator end(const List& list);

// перемещение итератора на следующий узел
bool next(Iterator& it);

// получение данных из узла, на который установлен итератор
Book* get(Iterator& it);

// получение данных из узла, следующего за тем, на который установлен итератор
Book* getNext(Iterator& it);

// обновление информационной части узла, на который установлен итератор
bool set(Iterator& it, Book* book);

// обновление информационной части узла, следуюшего за тем на который установлен итератор
bool setNext(Iterator& it, Book* book);

// проверка, установлен ли итератор на список
bool isSet(const Iterator& it);

// добавление нового узла, после того узла, на который установлен итератор
bool add(List& list, Iterator& it, Book* book);

// удаление узла, следующего за тем, на который установлен итератор
bool remove(Book& book, List& list, const Iterator& it);

// сравнение итераторов
bool operator == (Iterator& it1, Iterator& it2);
bool operator != (const Iterator& it1, const Iterator& it2);

#endif // ITERATOR_H
