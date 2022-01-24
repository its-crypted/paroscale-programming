#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fd;
	char dir[100], f_name[25];
	//char *ptr;
//	char *f_name = malloc(25 * sizeof(char));
//	ptr = (char *)malloc(100 * sizeof(char));
	printf("Enter the location to create a file: ");
	scanf("%s", dir);
	printf("Enter the file name: ");
	scanf("%s", f_name);
	strcat(dir, f_name);
	open(dir, O_CREAT, 00700);
	printf("%s\n", dir);
	return 0;
}
