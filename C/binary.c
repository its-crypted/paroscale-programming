/* This is binary search. This is algorithm uses divide and conquer method.
 * In binary search the array must be sorted.
 */

#include <stdio.h>

int main(){
	int num, low, end, mid;
	int doors[] = {1, 4, 5, 9, 11, 18, 19, 24, 27, 32, 36, 37, 41, 50};

	int doors_len = sizeof(doors) / sizeof(doors[0]);

	printf("Enter element for search: ");
	scanf("%d", &num);
	
	low = 0;
	end = doors_len - 1;
	mid = (end + low) / 2;
	
	while (low <= end) {
		if(num == doors[mid]){
			printf("The element is found\n");
			break;
		}
		else if(doors[mid] < num)
			low = mid + 1;
		else
			end = mid - 1;
		mid = (low + end) / 2;
	}
	if (low > end)
		printf("%d Not found!\n", num);

	return 0;
}
