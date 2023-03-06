#include "prints.h"

using namespace std;

void testStaticList();
void testDynamicList();
void testLinkedList();
void testList();
void testQueue();
void testStack();

int main() {
    testStaticList();
    testDynamicList();
    testList();
    testQueue();
    testStack();
    testLinkedList();
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

    SBookList list = SBookList {};
    list.books[0] = firstBook;
    list.size = 1;
    staticAddBook(&list, newBook, 1);
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

    DBookList dynamicBookList = DBookList {
        books,
        1
    };

    dynamicAddBook(&dynamicBookList, newBook, 1);
    print(&dynamicBookList);
    dynamicRemoveBook(&dynamicBookList, 2);
    print(&dynamicBookList);
}

void testLinkedList() {
    printf("\nLinked list:\n");
    LinkedList list = initLinkedList();

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

    pushFront(&list, firstBook);
    pushBack(&list, newBook);
    print(&list);
    popBack(&list);
    popFront(&list);
    print(&list);
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

    Node* list = init(firstBook);
    Node* newNode = addBook(list, newBook);
    addBook(newNode, superNewBook);
    print(list);
    deleteBook(newNode, list);
    print(list);
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

    push(&queue, firstBook);
    push(&queue, newBook);
    print(&queue);
    Book* poppedBook = (Book*)malloc(sizeof(Book));
    pop(poppedBook, &queue);
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

    push(&stack, firstBook);
    push(&stack, newBook);
    print(&stack);
    Book* poppedBook = (Book*)malloc(sizeof(Book));
    pop(poppedBook, &stack);
    print(poppedBook);
    print(&stack);
}
