#include <stdio.h>
#include <stdlib.h>

int main(){
	int *x;
	char *y;
	x = malloc(sizeof(int));
	printf("Enter the number for print: ");
	scanf("%i", x);

	printf("The value of x is %i\n", *x);
	free(x);


}
