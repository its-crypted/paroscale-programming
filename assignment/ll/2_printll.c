/* print the values of the linked list */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}node;

void printll(node *head);

int main(){
	node *head = malloc(sizeof(node));
	head->num = 12;
	head->next = NULL;

	node *c = malloc(sizeof(node));
	c->num = 32;
	c->next = NULL;
	head->next = c;

	c = malloc(sizeof(node));
	c->num = 23;
	c->next = NULL;
	head->next->next = c;

	printll(head);

}

void printll(node *head){
	if(head == NULL)
		printf("Linked list empty\n");
	node *ptr;
	ptr = head;
	while(ptr != NULL){
		printf("%d\n", ptr->num);
		ptr = ptr->next;
	}
}
