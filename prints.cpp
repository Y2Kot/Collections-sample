#include "prints.h"

void print(Book* book)
{
	printf("%s by %s, pages: %d, rating: %f\n", book->name, book->author, book->pageCount, book->rating);
}

void print(SBookList* list)
{
	printf("[\n");
	for (int i = 0; i < list->size; i++)
		print(&(list->books[i]));
	printf("]\n");
}

void print(DBookList* list)
{
	printf("[\n");
	for (int i = 0; i < list->size; i++)
		print(&(list->books[i]));
	printf("]\n");
}

void print(LinkedList* list)
{
	printf("[\n");
	LinkedNode* tmp = list->head;
	LinkedNode* next = NULL;
	while (tmp) {
		next = tmp->next;
		print(&(tmp->data));
		tmp = next;
	}
	printf("]\n");
}

void print(Queue* queue)
{
	printf("[\n");
	Node* tmp = queue->head;
	Node* next = NULL;
	while (tmp) {
		next = tmp->next;
		print(&(tmp->data));
		tmp = next;
	}
	printf("]\n");
}

void print(Stack* stack)
{
	printf("[\n");
	Node* tmp = stack->top;
	Node* next = NULL;
	while (tmp) {
		next = tmp->next;
		print(&(tmp->data));
		tmp = next;
	}
	printf("]\n");
}

void print(Node* list)
{
	printf("[\n");
	Node* p = list;
	do {
		print(&(p->data));  // вывод адреса элемента p->data
		p = p->next;                // переход к следующему узлу
	} while (p != NULL);
	printf("]\n");
}
