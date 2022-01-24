#define _XOPEN_SOURCE 500
#include <ftw.h>	/* The file tree walk header */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>		/* read man 2 stat */
#include <sys/stat.h>		/*	<-|	   */
#include <unistd.h>		/*	<-|	   */

static int display_info(const char *fpath,
			const struct stat *sb,
             		int tflag, 
			struct FTW *ftwbuf);

typedef struct node{
	long ino;
	struct node *next;
}node;


int main(int argc, char *argv[])
{
	int flags = 0;

	if (argc > 2 && strchr(argv[2], 'd') != NULL)
		flags |= FTW_DEPTH;

	printf("File_type\tLevel\tFile_size\tPath\t\t\t\t\t\t Inode\t\tAccess_t\tModify_t\t c_time\t\t Depth\n");
	if (nftw((argc < 2) ? "." : argv[1], display_info, 20, flags) == -1) {
		perror("nftw");
		return -1;
	}
	exit(EXIT_SUCCESS);
}

static int display_info(const char *fpath,
			const struct stat *sb,
             		int tflag,
			struct FTW *ftwbuf)
{
	printf("%-3s\t\t%2d\t %7jd\t %-40s\t%ld\t%ld \t%ld \t%ld\t%s\n",
		(tflag == FTW_D) ?   "d"   : (tflag == FTW_DNR) ? "dnr" :
		(tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "f" :
		"???",
		ftwbuf->level, (intmax_t) sb->st_size,
		fpath, sb->st_ino, sb->st_atime, sb->st_mtime, sb->st_ctime, fpath + ftwbuf->base);
	
	node *n = malloc(sizeof(node));
	node *leaf = NULL;
	if(tflag == FTW_F){
		for(leaf = n; n != NULL; leaf = leaf->next){
			n->ino = sb->st_ino;
			n->next = NULL;
			leaf = n;
			break;
		}
	}
	for(node *tmp = leaf; tmp != NULL; tmp = tmp->next)
		printf("%ld\n", tmp->ino);
	return 0;           /* To tell nftw() to continue */
}
