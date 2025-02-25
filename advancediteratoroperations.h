#ifndef ADVANCEDITERATOROPERATIONS_H
#define ADVANCEDITERATOROPERATIONS_H

#include "lists.h"

// вывод списка
void printList(const List& list);

// добавление книги в порядке возрастания рейтинга
int insertSort(List& list, Book* book);

// удаление повторяющихся элементов списка
int removeRepeated(List& list);

// сортировка элементов списка по количеству страниц
void sortList(List& list);

#endif // ADVANCEDITERATOROPERATIONS_H
