/* This is an update for iterating over the subdirectories.
 * 
 * Adding to this is the printing the absolute path for each file for using 
 * getcwd(get current working directory)
 */

#include <stdio.h>
#include <dirent.h>	//read man 2 opendir
#include <stdlib.h>
#include <string.h>
#include <unistd.h>	/* used for getcwd(man 2 getcwd) */

void dir_content(char *dir_name);	/* A func to check content of dir */

int main(int argc, char *argv[]){
	dir_content(argv[1]);
	return 0;
}

void dir_content(char *dir_name){
	DIR *dir = opendir(dir_name);

	if(dir == NULL){
		return;
	}
	
	struct dirent *r_dir; /* a directory structure */
	r_dir = readdir(dir);
	printf("Reading files from: %s\n", dir_name);

 	char path[100] = {0};
 	while(r_dir != NULL) {
		printf("%s\n", r_dir->d_name);
		if(r_dir->d_type == DT_DIR && 
			strcmp(r_dir->d_name, ".") != 0 &&
			strcmp(r_dir->d_name, "..") != 0){
				strcpy(path, dir_name);
				strcat(path, "/");
				strcat(path, r_dir->d_name);
				dir_content(path);
		}
		r_dir = readdir(dir);
 	}
	closedir(dir);
 }
