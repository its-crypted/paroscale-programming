#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <libgen.h>
#include <ftw.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct node{
	long ino;
	long f_size;
	long a_tm;
	long m_tm;
	long c_tm;
	struct node *next;
}node;

node *c, *tmp = NULL, *loc;
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

void add_at_end(node *p);

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
	nftw((argc < 2) ? "." : argv[1], linked, 20, flags);
	printf("\n");
	printll(tmp);
	int num, fd;
	char f_name[100], dest[100], str_ent[100];
	char c, dl;
	struct stat fb;
	while(1){
		printf("1. Add a file\n");
		printf("2. Delete a file\n");
		printf("3. Add a directory\n");
		printf("4. Delete a directory\n");
		printf("Enter the operation num to perform\n");
		scanf(" %d", &num);
		switch(num){
		case 1:
			printf("File Name: ");
			scanf("%s", f_name);
			printf("Destination: ");
			scanf("%s", dest);
			strcat(dest, f_name);
			open(dest, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
			printf("File %s is successfully added.\n", f_name);
			printf("Do you want to write to this file (Y/N)? \n");
			scanf(" %c", &c);
			if(c == 'y' || c == 'Y'){
				FILE *f;
				f = fopen(dest, "w");
				printf("How many lines do you want to enter: ");
				scanf("%d", &num);
				printf("Enter content\n");
				for(int i = 0; i < num+1; i++){
					fgets(str_ent, sizeof str_ent, stdin);
					fputs(str_ent, f);
				}
				printf("The content you entered is written to the file\n");
				fclose(f);
				stat(dest, &fb);
				loc = malloc(sizeof(node));
				loc->ino	=	fb.st_ino;
				loc->f_size	=	fb.st_size;
				loc->a_tm	=	fb.st_atime;
				loc->m_tm	=	fb.st_mtime;
				loc->c_tm	=	fb.st_ctime;
				loc->next	= 	NULL;
				node *b;
				b = tmp;
				while(b->next != NULL)
					b = b->next;
				b->next = loc;
				printf("File added to linked list successfully\n");
				break;
			} else if( c == 'n' || c == 'N'){
				stat(dest, &fb);
				loc = malloc(sizeof(node));
				loc->ino	=	fb.st_ino;
				loc->f_size	=	fb.st_size;
				loc->a_tm	=	fb.st_atime;
				loc->m_tm	=	fb.st_mtime;
				loc->c_tm	=	fb.st_ctime;
				loc->next	= 	NULL;
				node *b;
				b = tmp;
				while(b->next != NULL)
					b = b->next;
				b->next = loc;
				printf("File added to linked list successfully\n");
				free(loc);
				break;
			}
		case 2:
			printf("File Name: ");
			scanf("%s", f_name);
			printf("Destination: ");
			scanf("%s", dest);
			strcat(dest, f_name);
			stat(dest, &fb);
			printf("The inode for removed file is: %ld\n", fb.st_ino);
			loc = malloc(sizeof(node));
			loc->ino	=	fb.st_ino;
			loc->f_size	=	fb.st_size;
			loc->a_tm	=	fb.st_atime;
			loc->m_tm	=	fb.st_mtime;
			loc->c_tm	=	fb.st_ctime;
			loc->next	= 	NULL;
			if(loc->ino == tmp->ino){
				tmp = tmp->next;
				printf("The node is shifted to next and break is here\n");
				break;
			} else {
				node *bu, *cu;
				bu = tmp;	//tmp
				cu = tmp;	//tmp2
				while(cu->ino != loc->ino){
					bu = cu;
					cu = cu->next;
				}
				bu->next = cu->next;
				free(cu);
				cu = NULL;
				unlink(dest);
				printf("File %s has been removed & linked list it updated.\n", f_name);
				break;
			}
		case 3:
			printf("Dir Name: ");
			scanf("%s", f_name);
			printf("\nDestination: ");
			scanf("%s", dest);
			strcat(dest, f_name);
			mkdir(dest, 00700);
			stat(dest, &fb);
			loc = malloc(sizeof(node));
			loc->ino	=	fb.st_ino;
			loc->f_size	=	fb.st_size;
			loc->a_tm	=	fb.st_atime;
			loc->m_tm	=	fb.st_mtime;
			loc->c_tm	=	fb.st_ctime;
			loc->next	= 	NULL;
			printf("Directory %s successfully added at %s\n", f_name, dest);
			break;
		case 4:
			printf("Dir Name: ");
			scanf("%s", f_name);
			printf("Destination: ");
			scanf("%s", dest);
			rmdir(dest);
			printf("The directory has been deleted successfully\n");
			break;
		default:
			printf("Operation doesn't exits\n");
			exit(0);
		}
		printf("Do you want to continue with file operations (Y/N)? ");
		scanf(" %c", &c);
		if(c == 'y' || c == 'Y')
			continue;
		else
			break;
	}
	while(1){
		printf("Do you want to print Director structure OR Linked List (D/L)? ");
		scanf(" %c", &dl);
		if(dl == 'd' || dl == 'D')
			nftw((argc < 2) ? "." : argv[1], disp, 20, flags);
		if(dl == 'l' || dl == 'L')
			printll(tmp);
		printf("Do you want to continue the print? ");
		scanf(" %c", &c);
		if(c == 'y' || c == 'Y')
			continue;
		else
			break;
		
	}
	free(tmp);
	exit(EXIT_SUCCESS);
}

/* ----------------Main exit--------------------*/

/* ----------------Display Dir tree structure --------------------*/


static int disp(const char *fpath,
	  const struct stat *s,
	  int typeflag,
	  struct FTW *ftw){

	printf("%-3s\t\t%7jd\t\t%-40s\t\t%ld\n",
		(typeflag == FTW_D) ? "d" : (typeflag == FTW_F) ? "f": "???",
		s->st_size, fpath, s->st_ino);

	return 0;
}	

/* ----------------xx-xx-------------------*/

/* -----------------Linked list function ----------------- */

static int linked(const char *fpath,
	  const struct stat *s,
	  int typeflag,
	  struct FTW *ftw){
		struct dirent *r;
		DIR *d;	
		int files = 0;
		if(typeflag == FTW_D){
			d= opendir(fpath);
			while((r = readdir(d)) != NULL)
				files++;
		}
		if(typeflag == FTW_F || files == 2){  
			if(head == NULL){
				head = malloc(sizeof(node));
				head->ino	=	s->st_ino;
				head->f_size	=	s->st_size;
				head->a_tm	=	s->st_atime;
				head->m_tm	=	s->st_mtime;
				head->c_tm	=	s->st_ctime;
				head->next	= 	NULL;
				tmp = head;
			} else if(head != NULL) { 
				node *c = (struct node *)malloc(sizeof(node));
				c->ino		=	s->st_ino;
				c->f_size	=	s->st_size;
				c->a_tm		=	s->st_atime;
				c->m_tm		=	s->st_mtime;
				c->c_tm		=	s->st_ctime;
				c->next		= 	NULL;
				add_at_end(c);
			}
		}
	return 0;
}

/* ------------------xx-------xx--------------------------- */

/* ---------------function to add at end ---------------- */

void add_at_end(node *p){
	node *c2 = (struct node *)malloc(sizeof(node));
	c2 = tmp;
	while(c2->next != NULL)
		c2 = c2->next;
	c2->next = p;
}

/* --------------------------x--x-------------------------*/

/* -----------------------Printing linked list ------------------------- */

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
		printf("\n");
	}
}

/* ------------------------x---x--------------------------------------- */


