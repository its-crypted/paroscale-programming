#include <stdio.h>

void meow();
void how();

int main(){
	for(int i = 0; i < 3; i++)
		meow();
	how(3);
}

//function declaration
void meow(){
	printf("MEOW\n");
}

void how(int n){
	//function using the variable
	for(int j = 0; j < n; j++)
		printf("HOW");
}
