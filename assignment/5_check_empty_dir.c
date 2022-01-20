#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int f = 0;
	DIR *d;
	struct dirent *r;
	d = opendir(argv[1]);
	while( (r=readdir(d)) != NULL ){	
		printf("File: %s\n", r->d_name);
		f++;
	}
	if(f == 2)
		printf("The directory is empty\n");
	else
		printf("No. of files present in dir %s are %d\n", argv[1], f);
	
	closedir(d);
	exit(0);
}
