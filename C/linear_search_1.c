/* This is linear search. The upper bound (O) runtime for this algorithm is 
 * linear i.e O(n) as the algorithm compares the given number by each element
 * in the array.
 * The LOWER BOUND for linear search will be Ω(1) because the element could
 * be found at first place.
 */
 
#include <stdio.h>

int main(){
	int num, i;
	printf("Enter the number to be searched");
	scanf("%d", &num);
	int door[] = {3, 88, 9, 7, 4, 1, 2,  77, 32, 74, 45};

	int door_len = sizeof(door) / sizeof(door[0]);

	/* following will be the comparision of the element enter with 
	 * element of array. if the comparison is true then values will be
	 * printed or else it'll exit the for loop and proceed further.
	 */

	for(i = 0; i < door_len; i++){
		if(num == door[i]){
			printf("The num %d is at %d\n", door[i], i+1);
			break;
		}
	}
		
	/* when the index i becomes equal to array length i.e the elements
	 * in that array are finished and the element we are looking for is
	 * not found
	 */
	if(i == door_len) 
		printf("Element not found in array\n");	
}
