#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int number;
	struct node *next;
} node;

int main(){
	node *list = NULL;	//list of size

	//add a number to a list
	node *n = malloc(sizeof(node));
	if(n == NULL)
		return 1;

	n-> number = 1;
	n-> next = NULL;

	//update list to point to new node
	list = n;

	//add a number to list
	n = malloc(sizeof(node));
	if(n == NULL){
		free(list);
		return 1;
	}
	n->number = 2;
	n->next = NULL;
	list->next = n;

	//add a number to list
	n = malloc(sizeof(node));
	
	if(n == NULL) {
		free(list->next);
		free(list);
		return 1;
	}

	n->number = 3;
	n->next = NULL;
	list->next->next = n;

	//print numbers
	for(node *tmp = list; tmp != NULL; tmp = tmp->next)
		printf("%i\n", tmp->number);
}
