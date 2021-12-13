/* Structures are used for creating user defined data types using 
 * predefined data types as well as the data types used in struct 
 * could be different as per defined.
 */

#include <stdio.h>
#include <string.h>

//Initialization of structure.

struct person{
	char name[100];
	char number[100];
};	//this is the name for data type.

int main(){
	struct person people[2];

	strcpy(people[0].name, "Carter");
	strcpy(people[0].number, "+1-223-767-2756");

	strcpy(people[1].name, "James");
	strcpy(people[1].number, "+1-667-876-2345");
	
	for(int i = 0; i < 2; i++){
		if(strcmp(people[i].name, "James") == 0) {
			printf("Found %s and no. is %s\n", people[i].name, people[i].number);
			return 0;
		}
	}
	printf("Not Found\n");
	return 1;
}
