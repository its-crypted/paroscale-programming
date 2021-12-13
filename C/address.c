#include <stdio.h>

int main(){
	int n = 50;
	int *p = &n;
	printf("%p\n%p\n", &n, p);	//this will provide the address
	printf("%i\n", *p);		//this will provide the value at address
}
