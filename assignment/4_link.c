#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct node{
	long ino;
	long f_size;
	long a_tm;
	long m_tm;
	long c_tm;
	struct node *next;
}node;

node *add_at_end(node *ptr,
		 long ino,
		 long f_size,
		 long a_tm,
		 long m_tm,
		 long c_tm);

static int disp(const char *fpath,
	  const struct stat *s,
	  int typeflag,
	  struct FTW *ftw);

int main(int argc, char *argv[]){
	int flags = 0;
	if(argc > 2 && strchr(argv[2], 'd') != NULL)
		flags |= FTW_DEPTH;

	printf("File_type\tF_size\t\tPath\t\t\t\t\t\t\tInode\n");

	if(nftw((argc < 2) ? "." : argv[1], disp, 20, flags) == -1) {
		perror("nftw");
		return -1;
	}
	exit(EXIT_SUCCESS);
}

static int disp(const char *fpath,
	  const struct stat *s,
	  int typeflag,
	  struct FTW *ftw) {

	printf("%-3s\t\t%7jd\t\t%-40s\t\t%ld\n",
		(typeflag == FTW_D) ? "d" : (typeflag == FTW_F) ? "f": "???",
		s->st_size, fpath, s->st_ino);
	node *head = malloc(sizeof(node));
	if(typeflag == FTW_F){
		head->ino	=	s->st_ino;
		head->f_size	=	s->st_size;
		head->a_tm	=	s->st_atime;
		head->m_tm	=	s->st_mtime;
		head->c_tm	=	s->st_ctime;
		head->next	= 	NULL;
	}	
		node *tmp = head;
		node *ptr;
		ptr = add_at_end(tmp, s->st_ino,
			   s->st_size,
			   s->st_atime,
			   s->st_mtime,
			   s->st_ctime);

		/* print func */
		while(ptr != NULL) {
			printf("%ld\n", ptr->ino);
			printf("%ld\n", ptr->f_size);
			printf("%ld\n", ptr->a_tm);
			printf("%ld\n", ptr->m_tm);
			printf("%ld\n", ptr->c_tm);
			ptr = ptr->next;
		}
	return 0;
}

node *add_at_end(node *ptr,
		 long ino,
		 long f_size,
		 long a_tm,
		 long m_tm,
		 long c_tm){
		node *tmp = malloc(sizeof(node));
		tmp->ino	=	ino;
               	tmp->f_size	=	f_size;	
               	tmp->a_tm   	=	a_tm;
                tmp->m_tm	=	m_tm;
                tmp->c_tm	=	c_tm;
		tmp->next	=	NULL;

		ptr->next = tmp;
		return tmp;
}
