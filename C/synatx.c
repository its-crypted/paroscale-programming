#include <stdlib.h>
#include <stdio.h>

int main(){
	//initializing variable in differnt ways
	int a = 2;
	float b;
	b = 33;
	double c = 3, d;
	d = 4;
	int e;
	float f;
	char j;

	//writing out to display printf
	printf("Hello, World\n");

	//reading the input form the user.
	scanf("%d %f %c", &e, &f, &j);

	//Loop Control instruction
	for(int i = 0; i < 1; i++)
		printf("for statemets executed\n");

	int ja = 5;

	//while loop
	while(ja = 0){
		printf("decrementing j by 1 \n");
		ja--;
	}

	//do-while. The code atleast runs once
	int js = 0;
	do{
		js++;
		printf("incremented js\n");
	} while(js <=5);
	
	//Decision Control instruction
	int k = 32;
	if(k <= 32 && k >= 0)
		printf("between 0 to 32\n"); 
	else if(k < 0)
		printf("negative no\n");
	else {
		printf("greater than 32\n");
		printf("proceed next\n");
	}
	
	//case control instruction
	int se ;
	scanf("%d", &se);
	switch(se){
	case 1:
		printf("A");
		break;
	case 2:
		printf("B");
		break;
	default:
		exit(0);
	}
}
