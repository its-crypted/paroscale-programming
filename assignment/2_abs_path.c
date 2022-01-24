/* This is a problem where the cli argument is given as directory name
 * The function is used to iterate over all the files in the same directory
 * It doesn't iterate over subdirs in the dir.
 * Adding to this is the printing the absolute path for each file for using 
 * getcwd(get current working directory)
 */

#include <stdio.h>
#include <dirent.h>	//read man 2 opendir
#include <stdlib.h>
#include <string.h>
#include <unistd.h>	/* used for getcwd(man 2 getcwd) */

//void dir_content(DIR *dir);	/* A func to check content of dir */

int main(int argc, char *argv[]){
	DIR *d;
	char *dname = argv[1];
	d = opendir(argv[1]);	/* opens a dir provided in as argument to cli */
	printf("we are in %s\n", ".");

	//dir_content(d);		/* function call */
	closedir(d);	/* closes the opened dir */
}

//void dir_content(DIR *dir){
// 	struct dirent *r_dir; /* a directory structure */
// 	char *file_name;
// 	char buf[1000];
//
// 	while((r_dir = readdir(dir)) != NULL) {
// 		file_name = r_dir->d_name;
// 		printf("%s\n", file_name);
// 		char *b;
// 		printf("|-> %s", b);
// 		printf("\n");
// 	}
// }
