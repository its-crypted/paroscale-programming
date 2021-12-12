#include <stdio.h>

int main(){
	int doors[] = {23, 2, 4, 88, 12, 67, 68, 99, 26};
	int num, i;

	printf("Enter the no to find: ");
	scanf("%d", &num);
	int len = sizeof(doors) / sizeof(doors[0]);
	for(i = 0; i < len; i++){
		if(num == doors[i]){
			printf("Found\n");
			return 0;
		}
	}
	printf("Not Found\n");
	return 1;
}
