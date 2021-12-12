/* This Linear search is created using function */

#include <stdio.h>

void linS(int door[], int search, int num);

int main(){
	int num, door[100], search;
	printf("Enter the no. of elements array: ");
	scanf("%d", &num);

	for(int i = 0; i < num; i++) {
		printf("Enter the element of array\n");
		scanf("%d", &door[i]);
	}	

	printf("Enter the Element to be searched: ");
	scanf("%d", &search);

	linS(door, search, num);
}

void linS(int door[], int search, int num){
	int i;
	for(i = 0; i < num; i++){
		if(search == door[i]){
			printf("Element %d is at %d\n", door[i], i+1);
			break;
		}
	}
	if (i == num){
		printf("Element not Found\n");
	}
}
