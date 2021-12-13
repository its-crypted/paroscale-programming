#include <stdio.h>

int main(){
	char *s = "HI!";
	/* in *s the * is a derefrence operator which will give the value of
	 * variable.
	 * As the next addressess are contigious then we can just increment
	 * the pointer.
	 */

	printf("%c\n", *s);
	printf("%c\n", *(s + 1));
	printf("%c\n", *(s + 2));
	printf("%c\n", *(s + 3));

	int numbers[] = {4, 5, 6, 7, 8, 2, 1};

	printf("%i\n", *numbers);
	for(int i = 0; i < 7; i++)
		printf("%i\n", *(numbers + i));
	/*printf("%i\n", *(numbers + 1));
	printf("%i\n", *(numbers + 2));
	printf("%i\n", *(numbers+ 3));
	printf("%i\n", *(numbers+ 4));
	printf("%i\n", *(numbers + 5));
	printf("%i\n", *(numbers + 6));
	*/	
}
