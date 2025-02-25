#include "prints.h"
#include "advancediteratoroperations.h"
#include <stdlib.h>

void testStaticList();
void testDynamicList();
void testLinkedList();
void testList();
void testQueue();
void testStack();
void testIterator();

int main() {
   testStaticList();
   testDynamicList();
   testLinkedList();
   testList();
   testQueue();
   testStack();
   testIterator();
    return 0;
}

void testStaticList() {
    printf("\nStatic list:\n");

    Book firstBook = Book {
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book {
            "New Book",
            "Author",
            100,
            10
    };
    
    SBookCollection list = SBookCollection {};
    // Эта реализация должна быть скрыта за функцией (пример: staticAddBook)
    list.books[0] = firstBook;
    list.size = 1;
    staticAddBook(&list, &newBook, 1);
    print(&list);
    staticRemoveBook(&list, 0);
    print(&list);
}

void testDynamicList() {
    printf("\nDynamic list:\n");
    Book* books = (Book*)calloc(1, sizeof(Book));

    books[0] = Book {
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book {
            "New Book",
            "Author",
            100,
            10
    };
    
    DBookCollection dynamicBookList = DBookCollection {
        .books = books,
        .size = 1
    };

    dynamicAddBook(&dynamicBookList, &newBook, 1);
    print(&dynamicBookList);
    dynamicRemoveBook(&dynamicBookList, 2);
    print(&dynamicBookList);
}

void testLinkedList() {
    printf("\nLinked list:\n");
    LinkedList* list = initLinkedList();

    Book firstBook = Book {
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book {
            "New Book",
            "Author",
            100,
            10
    };

    pushFront(list, &firstBook);
    pushBack(list, &newBook);
    print(list);
    popBack(list, NULL);
    popFront(list, NULL);
    print(list);

    disposeList(list);
}

void testList() {
    printf("\nList:\n");

    Book firstBook = Book {
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book {
            "New Book",
            "Author",
            100,
            10
    };

    Book superNewBook = Book {
            "Super New Book",
            "Author",
            1000,
            5
    };

    List list = init(&firstBook);
    pushEnd(&list, &newBook);
    pushStart(&list, &superNewBook);
    print(&list);
    deleteBookByName(&list, newBook.name);
    print(&list);
}

void testQueue() {
    printf("\nQueue:\n");
    Queue queue = initQueue();

    Book firstBook = Book {
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book {
            "New Book",
            "Author",
            100,
            10
    };

    push(&queue, &firstBook);
    push(&queue, &newBook);
    print(&queue);
    Book* poppedBook = (Book*)malloc(sizeof(Book));
    pop(&queue, poppedBook);
    print(poppedBook);
    print(&queue);
}

void testStack() {
    printf("\nStack:\n");
    Stack stack = initStack();

    Book firstBook = Book {
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book {
            "New Book",
            "Author",
            100,
            10
    };

    push(&stack, &firstBook);
    push(&stack, &newBook);
    print(&stack);
    Book* poppedBook = (Book*)malloc(sizeof(Book));
    pop(&stack, poppedBook);
    print(poppedBook);
    print(&stack);
}

void testIterator() {
    printf("\nIterator:\n");
    Book firstBook = Book {
            "First Book",
            "Author",
            1,
            1
    };

    Book secondBook = Book {
            "Second Book",
            "Author",
            1,
            1
    };

    Book sixthBook = Book {
            "Second Book",
            "Author",
            1,
            6
    };

    Book newBook = Book {
            "New Book",
            "Author",
            100,
            10
    };

    Book superNewBook = Book {
            "Super New Book",
            "Author",
            1000,
            5
    };

    printf("\nIterator:List:\n");
    List list = init(&firstBook);
    Iterator it = begin(list);
    add(list, it, &newBook);
    next(it);
    add(list, it, &superNewBook);
    next(it);
    add(list, it, &sixthBook);
    printList(list);
    sortList(list);
    printf("\nIterator:List:After sort:\n");
    printList(list);

    printf("\nIterator:SortedList:\n");
    List sortedList = init(&superNewBook);
    insertSort(sortedList, &firstBook);
    insertSort(sortedList, &newBook);
    insertSort(sortedList, &newBook);
    insertSort(sortedList, &firstBook);
    insertSort(sortedList, &firstBook);
    printList(sortedList);
    removeRepeated(sortedList);
    printf("\nIterator:SortedList:Removed dublicates:\n");
    printList(sortedList);
}
