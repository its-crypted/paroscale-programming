#include <stdio.h>

void draw(int h);

int main(){
	int h;
	printf("Enter the height: ");
	scanf("%d", &h);

	draw(h);
}

void draw(int h){
	if(h <= 0)
		return;
	
	draw(h - 1);

	for(int i = 0; i < h; i++)
		printf("#");
	printf("\n");
}
