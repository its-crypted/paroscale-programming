#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	char *s = "hi!";
	char *t = malloc(strlen(s) + 1);
	if (t == NULL)
		return 1;
	strcpy(t, s);

	if (strlen(t) > 0)
		t[0] = toupper(t[0]);

	printf("%s\n", t);
	free(t);
}
