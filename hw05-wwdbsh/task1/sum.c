#include<stdio.h>
#include<stdlib.h>

int get_sum(int* num, int len); // Prototype

int main(int argc, char *argv[]) // Main function
{
	int i = 1, j = 0; // Initializing values.
	int* number = (int*)malloc(sizeof(int)); // Allocating memory.
	
	if(argv[1] == NULL) // Case: no arguments
	{
		printf("no input numbers\n");
		fflush(stdout);
	}
	else
	{	
		do
		{
			number[j] = strtol(argv[i], NULL, 10); // Convert char to int.
			i++; // Increasing i by adding 1.
			j++; // Increasing j by adding 1.
			
		}while(argv[i] != NULL); // loop condition

		printf("%d\n", get_sum(number, argc)); // Call function and print sum value.
		fflush(stdout);
	}

	free(number); // Free number.
	number = NULL; // point to NULL.

	return 0; 
}

int get_sum(int* num, int len) // get_sum function
{
	int i, sum; // Declaring values.

	for(i = 0; i < (len-1); i++)
	{
		sum += num[i]; // Adding num[i] to sum.
	}

	return sum; // Return sum.
}