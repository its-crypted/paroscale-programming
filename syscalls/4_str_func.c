#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char str[24];

	/* eg 1 */
	sprintf(str, "Hello, World!");
	printf("%s\n", str);

	/* eg 2 */
	int i = 4;
	sprintf(str, "Value of i = %d", i);
	printf("%s\n", str);
	
	/* eg 3 */
	int n = strlen(str);
	printf("Length of str is %d\n", n);

	/* eg 4 */
	char str2[24];
	strcpy(str2, str);
	printf("%s\n", str2);


	/* eg 5 */
	strfry(str2);
	printf("%s\n", str2);

	return 0;
}
