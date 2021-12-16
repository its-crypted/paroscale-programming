/* Write a program to change the value of a variable to ten times of
 * its current value. Write a function and pass the value by refrence.
 */

#include <stdio.h>

void pass_val(int *x);

int main(){
	int x = 2;
	pass_val(&x);

}

void pass_val(int *x){
	*x = *x * 10;
	printf("The value is %d\n", *x);
}
