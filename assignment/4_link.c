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

node *tmp;
static node *head = NULL;

void printll(node *head);	//printing of linked list

static int disp(const char *fpath,
		  const struct stat *s,
		  int typeflag,
		  struct FTW *ftw);

static int linked(const char *fpath,
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
	printf("\n");
	nftw((argc < 2) ? "." : argv[1], linked, 20, flags);
	exit(EXIT_SUCCESS);
}

static int disp(const char *fpath,
	  const struct stat *s,
	  int typeflag,
	  struct FTW *ftw) {

	printf("%-3s\t\t%7jd\t\t%-40s\t\t%ld\n",
		(typeflag == FTW_D) ? "d" : (typeflag == FTW_F) ? "f": "???",
		s->st_size, fpath, s->st_ino);
	return 0;
}
/*---------------------clear---------------------------*/

/* Linked list function */

static int linked(const char *fpath,
	  const struct stat *s,
	  int typeflag,
	struct FTW *ftw){ 
	if(typeflag == FTW_F){
		if(head == NULL){
			head = malloc(sizeof(node));
			head->ino	=	s->st_ino;
			head->f_size	=	s->st_size;
			head->a_tm	=	s->st_atime;
			head->m_tm	=	s->st_mtime;
			head->c_tm	=	s->st_ctime;
			head->next	= 	NULL;
		} tmp = head;
		  head = tmp->next;
		  printll(tmp);
//		  else if(head != NULL) {
//
//			node *ptr = malloc(sizeof(node));
//			ptr->ino	=	s->st_ino;
//			ptr->f_size	=	s->st_size;
//			ptr->a_tm	=	s->st_atime;
//			ptr->m_tm	=	s->st_mtime;
//			ptr->c_tm	=	s->st_ctime;
//			ptr->next	= 	NULL;
//
//			
//			printf("%ld\n", ptr->ino);
//			printf("%ld\n", ptr->f_size);
//			printf("%ld\n", ptr->a_tm);
//			printf("%ld\n", ptr->m_tm);
//			printf("%ld\n", ptr->c_tm);
//			printf("\n");
//			tmp->next = ptr;
//			ptr = ptr->next;
//		}
	}		
	return 0;
}

void printll(node *head){
	node *ptr;
	if(head == NULL)
		printf("The linked list is NULL\n");
	ptr = head;
	while(ptr != NULL){
		printf("%ld\n", ptr->ino);
		printf("%ld\n", ptr->f_size);
		printf("%ld\n", ptr->a_tm);
		printf("%ld\n", ptr->m_tm);
		printf("%ld\n", ptr->c_tm);
		ptr = ptr->next;
	}
}
