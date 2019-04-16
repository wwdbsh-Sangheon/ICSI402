#include <stdio.h>
#define NUMBER_COUNT_MAX 100

int permute_array(int* arr, size_t len); // Prototype

// Main function
int main(void)
{
	int number, arr[NUMBER_COUNT_MAX]; // Declaring number and arr.
	unsigned int i;	// Declaring i as an unsigned int.
	size_t len; // Declaring len as a size_t

	// Prompt the user to enter numbers and store them in array.
	for(i = 0; i < NUMBER_COUNT_MAX && scanf("%d", &arr[i]) != EOF; i++)
	{
		len++; // Increasing len by adding 1.
	}

  	if(arr[0] != '\0') // If array has elements, call function and print out numbers. Otherwise, print invalid msg.
  	{
  		for(i = 0; arr[i] != '\0'; i++)
  		{
  			number = permute_array(arr+i, len); // Call function and store return value in number.
  			printf("%d ", number);
  			len--; // Decreasing len by subtracting 1.
  		}
  	}
  	else
  	{
  		printf("no input numbers");
  	}	

  	printf("\n"); 

	return 0;
}