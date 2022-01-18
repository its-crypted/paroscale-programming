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

node *c, *tmp = NULL;
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

void add_at_end(node *h, node *p);

/* ------------------Main---------------------*/
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
//	nftw((argc < 2) ? "." : argv[1], linked, 20, flags);
	printll(tmp);
	exit(EXIT_SUCCESS);
}

static int disp(const char *fpath,
	  const struct stat *s,
	  int typeflag,
	  struct FTW *ftw){

	printf("%-3s\t\t%7jd\t\t%-40s\t\t%ld\n",
		(typeflag == FTW_D) ? "d" : (typeflag == FTW_F) ? "f": "???",
		s->st_size, fpath, s->st_ino);
	struct dirent *r;
	if(typeflag == FTW_F){  
		if(head == NULL){
			head = malloc(sizeof(node));
			head->ino	=	s->st_ino;
			head->f_size	=	s->st_size;
			head->a_tm	=	s->st_atime;
			head->m_tm	=	s->st_mtime;
			head->c_tm	=	s->st_ctime;
			head->next	= 	NULL;
			printf("%ld\n", head->ino);
			printf("%ld\n", head->f_size);
			printf("%ld\n", head->a_tm);
			printf("%ld\n", head->m_tm);
			printf("%ld\n", head->c_tm);
			tmp = head;
		} else if(head != NULL) { 
			c->ino		=	s->st_ino;
			c->f_size	=	s->st_size;
			c->a_tm		=	s->st_atime;
			c->m_tm		=	s->st_mtime;
			c->c_tm		=	s->st_ctime;
			c->next		= 	NULL;
			add_at_end(tmp, c);
			printf("hello, debug\n");
			printf("%ld\n", tmp->ino);
			printf("%ld\n", tmp->f_size);
			printf("%ld\n", tmp->a_tm);
			printf("%ld\n", tmp->m_tm);
			printf("%ld\n", tmp->c_tm);

//			printf("Hello debug\n");
//			node *ptr = malloc(sizeof(node));
//			ptr->ino	=	s->st_ino;
//			ptr->f_size	=	s->st_size;
//			ptr->a_tm	=	s->st_atime;
//			ptr->m_tm	=	s->st_mtime;
//			ptr->c_tm	=	s->st_ctime;
//			ptr->next	= 	NULL;
//			tmp = add_at_end(tmp, ptr);
		}
	}
	return 0;
}	

void add_at_end(node *h, node *p){
	node *ptr, *c1 = malloc(sizeof(node));
	ptr = h;
	c1 = p;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = c1;
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

/*
 -------------------extra---------------- x
		while(tmp != NULL){
			printf("%ld\n", tmp->ino);
			printf("%ld\n", tmp->f_size);
			printf("%ld\n", tmp->a_tm);
			printf("%ld\n", tmp->m_tm);
			printf("%ld\n", tmp->c_tm);
			tmp = tmp->next;
			printf("\n");
		}
			while(head != NULL){
				printf("%ld\n", head->ino);
				printf("%ld\n", head->f_size);
				printf("%ld\n", head->a_tm);
				printf("%ld\n", head->m_tm);
				printf("%ld\n", head->c_tm);
			}
*---------------------clear---------------------------*
			if(tmp != NULL){
				tmp->next = ptr;
				tmp = tmp->next;
			}

* Linked list function *

//static int linked(const char *fpath,
//	  const struct stat *s,
//	  int typeflag,
//	struct FTW *ftw){ 
//		  else if(head != NULL) {
//		  	tmp = head;
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
 */
