#include <stdio.h>

int main(){
	char *s = "HI!";
	char *p = &s[0];
	printf("%s\n", s);
	/*below will print the address of s & will be same
	* The pointer s points to the first element of the string HI!.
	* The next addressess are contigious with respect to the first address.
	*/
	printf("%p\n", p);
	printf("%p\n", s);

	printf("The addresses for the s are\n");
	printf("%p\n", &s[0]);
	printf("%p\n", &s[1]);
	printf("%p\n", &s[2]);
	printf("%p\n", &s[3]);
}

