#include <stdio.h>
#include <sys/types.h>		//stat
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>		// for memory allocation
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	open(argv[1], O_CREAT, S_IRUSR | S_IWUSR);
	struct stat buff;
	char mtm[100];
	stat(argv[1], &buff);
	printf("%ld\n", buff.st_ino);
	printf("%ld\n", buff.st_nlink);
	printf("%d\n", buff.st_uid);
	printf("%d\n", buff.st_gid);
	printf("%d\n", buff.st_mode);
	strcpy(mtm, ctime(&buff.st_mtime));
	printf("modify time = %s\n", mtm);

	return 0;
}
