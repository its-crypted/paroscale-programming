#include <stdio.h>

void swap(int *x, int *y);

int main(){
	int x, y;
	printf("Enter the value of x & y\n");
	scanf("%i\n%i", &x, &y);
	printf("The value before swap is x: %d & y: %d\n", x, y);
	swap(&x, &y);
	printf("Values after swap is x: %d & y: %d\n", x,y);
}
/*
void swap(int x, int y){
	int temp = x;
	x = y;
	y = temp;
	printf("a is %i, b is %i\n", x, y);
}
*/
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
