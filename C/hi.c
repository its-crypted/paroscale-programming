#include <stdio.h>

int main(){
	char c1 = 'H';
	char c2 = 'I';
	char c3 = '!';

	//this will print HI!
	printf("%c%c%c\n", c1, c2, c3);
	
	//this will give the ASCII values for the characters
	//C will do this conversion implicitly
	printf("%i %i %i\n", c1, c2, c3);
	
	//below is called typecasting. explicitly converting chars to ints
	printf("%i %i %i\n",(int) c1, (int) c2,(int) c3);
}

