#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	 * int list[3];	This is identical to int list = malloc(3 * sizeof(int));
	 * The first list[3] puts the array on the stack and the second 
	 * creating and array of size 3 and putting it on the heap.
	 */
	int *list;
	list = malloc(3 * sizeof(int));
	
	/* below "if" is used for the checking if the comptuer memory is
	 * out of space and it'll return the value 1
	 */

	if(list == NULL)
		return 1;

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	/* above assigning can be represented as 
	 * *list = 1;
	 * *(list + 1) = 2;
	 * *(list + 2) = 3;
	 */

	 for(int i = 0; i < 3; i++)
	 	printf("%i\n",list[i]);
	
	/* Resixe old array to be of size 4
	 */

	int *tmp = realloc(list, 4 * sizeof(int));

	if(tmp == NULL){
		free(list);
		return 1;
	}

	/* Below will copy all the elements of the list to tmp */

	tmp[3] = 4;	//the next added number will get the value 4

	list = tmp;	//This will create a new list.

	printf("\nThe newly added element list\n");
	for(int i = 0; i < 4; i++)
		printf("%i\n", list[i]);

	free(list);	//This will free the the new created list. this is same as freeing tmp and clearing memory.
	return 0;
}
