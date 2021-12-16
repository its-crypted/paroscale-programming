/* write a program to print the address of a variable.
 * sue this address to get the value of this variable.
 */
#include <stdio.h>

int main(){
	int x = 21;
	int *p = &x;
	printf("The address of x is %p\n", p);
	printf("The value of x is %i\n", *p);
	return 0;
}
