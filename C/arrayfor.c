#include <stdio.h>

//This code will be done using the malloc function ahead

int main(){
	int n;
	printf("How many elements");
	scanf("%d", &n);
	int scores[n];
	int len_of_arr = sizeof(scores) / sizeof(scores[0]);
	printf("Length of array %d \n", len_of_arr); 
	for(int i = 0; i < len_of_arr; i++){
		scanf("%d\n", &scores[i]);
	}

	printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}

