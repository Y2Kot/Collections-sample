#include <iostream>
#include "prints.h"

using namespace std;

void testStaticList();
void testDynamicList();
void testLinkedList();
void testList();
void testQueue();
void testStack();

int main()
{
    testStaticList();
    testDynamicList();
    testLinkedList();
    testList();
    testQueue();
    testStack();
    return 0;
}

void testStaticList()
{
    printf_s("\nStatic list:\n");

    Book firstBook = Book{
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book{
            "New Book",
            "Author",
            100,
            10
    };

    Book books[2] = { firstBook, newBook };
    SBookList list = SBookList{};
    list.books[0] = firstBook;
    list.size = 1;
    staticAddBook(&list, newBook, 1);
    printStaticBookList(list);
    staticRemoveBook(&list, 0);
    printStaticBookList(list);
}

void testDynamicList()
{
    printf_s("\nDynamic list:\n");
    Book* books = (Book*)calloc(1, sizeof(Book));

    books[0] = Book{
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book{
            "New Book",
            "Author",
            100,
            10
    };

    DBookList dynamicBookList = DBookList{
        books,
        1
    };

    dynamicAddBook(&dynamicBookList, newBook, 1);
    printDynamicBookList(dynamicBookList);
    dynamicRemoveBook(&dynamicBookList, 2);
    printDynamicBookList(dynamicBookList);
}

void testLinkedList() {
    printf_s("\nLinked list:\n");
    LinkedList list = initLinkedList();

    Book firstBook = Book{
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book{
            "New Book",
            "Author",
            100,
            10
    };

    pushFront(&list, firstBook);
    pushBack(&list, newBook);
    printLinkedBookList(list);
    popBack(&list);
    popFront(&list);
    printLinkedBookList(list);
}

void testList()
{
    printf_s("\nList:\n");

    Book firstBook = Book{
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book{
            "New Book",
            "Author",
            100,
            10
    };

    Book superNewBook = Book{
            "Super New Book",
            "Author",
            1000,
            5
    };

    Node* list = init(firstBook);
    Node* newNode = addBook(list, newBook);
    addBook(newNode, superNewBook);
    printBookList(list);
    deleteBook(newNode, list);
    printBookList(list);
}

void testQueue()
{
    printf_s("\nQueue:\n");
    Queue queue = initQueue();

    Book firstBook = Book{
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book{
            "New Book",
            "Author",
            100,
            10
    };

    push(&queue, firstBook);
    push(&queue, newBook);
    printBookQueue(queue);
    Book* poppedBook = (Book*)malloc(sizeof(Book));
    pop(poppedBook, &queue);
    printBook(*poppedBook);
    printBookQueue(queue);
}

void testStack()
{
    printf_s("\nStack:\n");
    Stack stack = initStack();

    Book firstBook = Book{
            "First Book",
            "Author",
            1,
            1
    };

    Book newBook = Book{
            "New Book",
            "Author",
            100,
            10
    };

    push(&stack, firstBook);
    push(&stack, newBook);
    printStack(stack);
    Book* poppedBook = (Book*)malloc(sizeof(Book));
    pop(poppedBook, &stack);
    printBook(*poppedBook);
    printStack(stack);
}
