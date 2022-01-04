/* This is a problem where the cli argument is given as directory name
 * The function is used to iterate over all the files in the same directory
 * It doesn't iterate over subdirs in the dir.
 */

#include <stdio.h>
#include <dirent.h>	//read man 2 opendir
#include <stdlib.h>
#include <string.h>

void dir_content(DIR *dir);	/* A func to check content of dir */

int main(int argc, char *argv[]){
	DIR *d;
	d = opendir(argv[1]);	/* opens a dir provided in as argument to cli */
	dir_content(d);		/* function call */
	close(d);	/* closes the opened dir */
}

void dir_content(DIR *dir){
	struct dirent *r_dir;	/* a directory structure */
	char *file_name;
	while((r_dir = readdir(dir)) != NULL) {
		file_name = r_dir->d_name;
		printf("%s\n", file_name);
	}
}
