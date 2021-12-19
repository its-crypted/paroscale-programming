#include <stdio.h>
#include <stdlib.h>

int main(){
	int *list;
	list = malloc(3 * sizeof(int));
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	/* above can be represented as 
	 * *list = 1;
	 * *(list + 1) = 2;
	 * *(list + 2) = 3;
	 */

	 for(int i = 0; i < 3; i++)
	 	printf("%d\n",list[i]);
	
	/* now to add the new value to list we need to create a new array of
	 * size 4 and then copy all the elements of the array. After copying
	 * add the next element
	 */

	 int *tmp = malloc(4 * sizeof(int));

	 for(int i = 0; i < 3; i++)
	 	list[i] = tmp[i];
	tmp[3] = 4;

	for(int i = 0; i < 4; i++)
		printf("%d\n", tmp[i]);

}
