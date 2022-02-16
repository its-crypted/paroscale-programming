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
	if (argv[1] == NULL) 
		return -1;
	
	struct stat buff;
	char mtm[25], atm[25], ctm[25];
	stat(argv[1], &buff);
	printf("%ld\n", buff.st_ino);
	printf("%ld\n", buff.st_nlink);
	printf("%d\n", buff.st_uid);
	printf("%d\n", buff.st_gid);
	printf("%d\n", buff.st_mode);
	strcpy(mtm, ctime(&buff.st_mtime));
	strcpy(atm, ctime(&buff.st_atime));
	strcpy(ctm, ctime(&buff.st_ctime));
	printf("modify time = %s\n", mtm);
	printf("access time = %s\n", atm);
	printf("change time = %s\n", ctm);

	return 0;
}
