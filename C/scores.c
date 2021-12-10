#include <stdio.h>

int main(){
	int score1 = 72;
	int score2 = 73;
	int score3 = 74;
	
	/*this won't work as the scores are assigned to int and even are
	 * divided by int hence, this'll not work
	 * to make it work we need to have atleast one of the value as float
	 * as 3.0 as divisor. And below is the ugly code.
	 */

	printf("Average of scores %f\n", (scores1 + scores2 + scores3) / 3);
}
