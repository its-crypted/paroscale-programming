#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[24] = "Hello World.";
	char *ptr = "World Hello.";

	printf("%s\n", str);
	printf("%s\n", ptr);

//	str = str + 1;	won't work 
	printf("%s\n", str);
	
	ptr = ptr + 1;
	printf("%s\n", ptr);

	return 0;
}
