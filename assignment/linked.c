#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>


typedef struct node{
	long int ino;
	long int f_size;
	long int a_tm;
	long int m_tm;
	long int c_tm;
	struct node *next;
}node;

struct node *add_at_end(node *ptr);

struct stat sb;
struct dirent *r;
node *head = NULL;
node *ptr = NULL;

int main(int argc, char *argv[]){
	DIR *d;

	d = opendir(argv[1]);

	while( (r = readdir(d)) != NULL){
		if(sb.st_mode == S_IFREG){
			head->ino 	= sb.st_ino;
			head->f_size	= sb.st_size;
			head->a_tm	= sb.st_atime;
			head->m_tm	= sb.st_mtime;
			head->c_tm	= sb.st_ctime;
			head->next	= NULL;
			add_at_end(head);
		}
			
	}
}


struct node *add_at_end(node *ptr){
	ptr = (struct node *)malloc(sizeof(node));
	
}
