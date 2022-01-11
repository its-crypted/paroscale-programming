#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}node;

void count_of_nodes(node *head);
int main(){
	node *head = malloc(sizeof(node));
	head->num = 1;
	head->next = NULL;
	printf("%d\n", head->num);

	node *current = malloc(sizeof(node));
	current->num = 2;
	current->next = NULL;
	/* take the value of current and place it into the null vlaue of head */
	head->next = current;
	printf("%d\n", head->next->num);

	current = malloc(sizeof(node));
	current->num = 3;
	current->next = NULL;

	head->next->next = current;
	printf("%d\n", head->next->next->num);

	count_of_nodes(head);
	return 0;
}

/* Count the nodes */

void count_of_nodes(node *head){
	int c = 0;
	node *ptr;
	if(head == NULL)
		printf("Linked list empty\n");
	ptr = head;
	while(ptr != NULL){
		c++;
		ptr = ptr->next;
	}
	printf("%d\n", c);
}

