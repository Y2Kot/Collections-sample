#include "advancediteratoroperations.h"
#include <string.h>
#include "prints.h"
#include "samplestructs.h"
#include "iterator.h"

bool operator != (const Book& it1, const Book& it2);

void printList (const List& list) {
    for (Iterator it = begin(list); isSet(it); next(it))
        print(&(it.current->data));
    printf ("\n");
}

int insertSort (List &list, Book* book) {
    int position = 0;
    Iterator it = begin(list);

    if (!isSet(it) || get(it)->rating >= book->rating)
        pushStart(&list, book); // почему прямое обращение к методу динамической структуры?
    else {
        for(position = 1; it != end(list) && getNext(it)->rating < book->rating; next(it), position++);
        add(list, it, book);
    }
    return position;
}

int removeRepeated(List& list) {
    int count = 0;

    for(Iterator it1 = begin (list); it1 != end(list);) {
        for(Iterator it2 = it1; it2 != end(list);) {
            if(*get(it1) != *getNext(it2)) // что сравнивается?
                next(it2);
            else {
                Book temp;
                remove(temp, list, it2);
                count++;
            }
        }
        if(getNext(it1))
            next(it1);
    }
    return count;
}

void sortList (List& list) {
    for (Iterator it1 = begin(list); it1 != end(list); next(it1)) {
        Book book = *get(it1);

        for (Iterator it2 = it1; next(it2), isSet(it2);) {
            if (book.rating > get(it2)->rating) {
                book = *get(it2);
                set(it2, get(it1));
                set(it1, &book);
            }
        }
    }
}

bool operator != (const Book& b1, const Book& b2) {
    return strcmp(b1.author, b2.author) || strcmp(b1.name, b2.name) || b1.pageCount != b2.pageCount || b1.rating != b2.rating;
}
