/* 
 * sort: The sort programme for linked list
 *
 * Totally different from the original idea of 
 * making up a new list. Instead we will 
 * try to sort and merge within the two lists. 
 *
 * Using recursion to simplify the function.
 *
 * Written by joel
 * Mar 9, 2019
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>			// for generating random numbers

typedef struct node {
	int data;
	struct node *next;
} Node;

/* merge n1 and n2 together, return the head of the new list */
Node *merge(Node *n1, Node *n2);

/* randomly generate a list, with random length and content, but already sorted */
void generate_list(Node **head);

/* print the whole list for checking */
void print_list(Node *head);

int main(void) 
{
	Node *n1, *n2;
	Node *new_n;

	srand(time(NULL));
	generate_list(&n1);
	generate_list(&n2);

	printf("n1: \n");
	print_list(n1);
	printf("n2: \n");
	print_list(n2);

	new_n = merge(n1, n2);
	printf("new n: \n");
	print_list(new_n);

	return 0;
}

Node *merge(Node *n1, Node *n2) 
{
	Node *head;

	if (n1 == NULL) 
		return n2;
	if (n2 == NULL) 
		return n1;

	if (n1->data < n2->data) {
		head = n1;
		head->next = merge(n1->next, n2);
	}
	else {
		head = n2;
		head->next = merge(n1, n2->next);
	}
	return head;
}

#define MAX_LENGTH 		20
#define INTERVIAL		10
#define MAX_VALUE		300
void generate_list(Node **head) 
{
	if (*head != NULL) {
		printf("generate_list(): the list is not empty\n");
	}
	else {
		int length;
		Node *ptr;
		
		do {
			length = rand() % (MAX_LENGTH + 1);
		} while (length <= 0);

		*head = ptr = (Node*)malloc(sizeof(Node));
		do {
			ptr->data = rand() % (MAX_VALUE + 1);
		} while (ptr->data > INTERVIAL);
		for (int i = 1; i < length; i ++) {
			ptr->next = (Node*)malloc(sizeof(Node));
			do {
				ptr->next->data = rand() % (MAX_VALUE + 1);
			} while (ptr->next->data < ptr->data || 
				(ptr->next->data - ptr->data) > INTERVIAL);
			ptr = ptr->next;
		}
		ptr->next = NULL;
	}
}

void print_list(Node *head) 
{
	for (int i = 0; head; head = head->next) {
		printf("%d", head->data);
		if (++i % 6 == 0) 
			putchar('\n');
		else 
			putchar(' ');
	}
	printf("\n\n");
}
