/* This is a program for capatilizing the characters given
 * Using getchar() & putchar()
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int d, c;
	c = getchar();

	while(c != EOF) {
		d = c;
		if (d >= 'a' || d <= 'z'){
			d = d - 32;	
			putchar(d);
		} else
			putchar(d);
		c = getchar();
	}
	printf("\n");
}
