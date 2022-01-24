/* Add a node at end of the linked list */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}node;

void add_at_end(node *head, int n);
void printll(node *head);

int main(){
	node *head = malloc(sizeof(node));
	head->num = 93;
	head->next = NULL;

	node *current = malloc(sizeof(node));
	current->num = 29;
	current->next = NULL;
	/* take the value of current and place it into the null vlaue of head */
	head->next = current;

	current = malloc(sizeof(node));
	current->num = 32;
	current->next = NULL;
	head->next->next = current;
	
	printf("List before adding an element\n");
	printll(head);

	add_at_end(head, 57);
	printf("List after adding the element\n");
	printll(head);

	return 0;
}

/* add a node at the end */

void add_at_end(node *head, int n){
	node *ptr, *tmp;
	ptr = head;
	tmp = malloc(sizeof(node));
	tmp->num =  n;
	tmp->next = NULL;

	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = tmp;
}

void printll(node *head){
	node *ptr;
	if(head == NULL)
		printf("The linked list is null\n");
	ptr = head;
	while(ptr != NULL){
		printf("%d\n", ptr->num);
		ptr = ptr->next;
	}
}
