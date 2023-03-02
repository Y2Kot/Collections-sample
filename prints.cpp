#include "prints.h"

void printBook(Book book)
{
	printf_s("%s by %s, pages: %d, rating: %f\n", book.name, book.author, book.pageCount, book.rating);
}

void printStaticBookList(SBookList list)
{
	printf_s("[\n");
	for (int i = 0; i < list.size; i++)
		printBook(list.books[i]);
	printf_s("]\n");
}

void printDynamicBookList(DBookList list)
{
	printf_s("[\n");
	for (int i = 0; i < list.size; i++)
		printBook(list.books[i]);
	printf_s("]\n");
}

void printLinkedBookList(LinkedList list)
{
	printf_s("[\n");
	LinkedListNode* tmp = list.head;
	LinkedListNode* next = NULL;
	while (tmp) {
		next = tmp->next;
		printBook(tmp->data);
		tmp = next;
	}
	printf_s("]\n");
}

void printBookQueue(Queue queue)
{
	printf_s("[\n");
	QueueNode* tmp = queue.head;
	QueueNode* next = NULL;
	while (tmp) {
		next = tmp->next;
		printBook(tmp->data);
		tmp = next;
	}
	printf_s("]\n");
}

void printStack(Stack stack)
{
	printf_s("[\n");
	StackNode* tmp = stack.top;
	StackNode* next = NULL;
	while (tmp) {
		next = tmp->next;
		printBook(tmp->data);
		tmp = next;
	}
	printf_s("]\n");
}

void printBookList(Node* list)
{
	printf_s("[\n");
	Node* p = list;
	do {
		printBook(p->data);  // вывод адреса элемента p->data
		p = p->next;                // переход к следующему узлу
	} while (p != NULL);
	printf_s("]\n");
}
