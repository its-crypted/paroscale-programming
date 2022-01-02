#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]){
	DIR *d;
	struct dirent *entry;
	int files = 0;
	d = opendir(argv[1]);
	if(d == NULL){
		printf("Unable to read dir");
		return(1);
	}
	else
		printf("Directory %s  is opened.\n", argv[1]);
	
	while(entry = readdir(d)){
		files++;
		printf("FILE %3d: %s\n", files, entry->d_name);
	}
	closedir(d);
	return(0);
}

