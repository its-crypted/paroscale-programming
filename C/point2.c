/* Write a program having a variable i. Print hte address of i.
 * Pass this variable to a function and print its address. Are these addresess
 * same? 
 */

#include <stdio.h>

void pass(int *a);

int main(){
	int i = 21;
	printf("The address of i in main is %p\n", &i);

	pass(&i);
	return 0;
}

void pass(int *a){
	printf("The address of i in func is %p\n", a);
}
