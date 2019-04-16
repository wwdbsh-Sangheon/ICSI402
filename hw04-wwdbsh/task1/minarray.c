#include <stdio.h>
#include <stdlib.h>
#define NUMBER_COUNT_MAX 100

int minimum_number(int numbers[], int n); // Prototype

int main(int argc, char *argv[])
{
	int numbers[NUMBER_COUNT_MAX];
	int min;

	min = minimum_number(numbers, NUMBER_COUNT_MAX); // Call function.

	if(min == '\0') // Case: there is nothing in array. Otherwise, print out min.
	{
		printf("no input numbers\n");
	}
	else
	{
  		printf("%d\n", min);
	}

  	return 0;
}
// Function for finding minimum number.
int minimum_number(int numbers[], int n)
{
  	unsigned int i = 0;
  	int min;
  	// Prompt the user to enter numbers, and store numbers in array.
	while (i < n && scanf("%d", &numbers[i]) != EOF)
  	{
    	i++;
  	}

  	if(numbers[0] == '\0') // Case: nothing in array.
  	{
  		min = numbers[0];
  	}
  	else if(numbers[1] == '\0') // Case: 1 number in array.
  	{
  		min = numbers[0];
  	}
	 else if(numbers[2] == '\0') // Case: 2 numbers in array.
  	{
		if(numbers[0] <= numbers[1])
  		{
  			min = numbers[0];
  		}
  		else
  		{
  			min = numbers[1];
  		}
  	}
  	else // Case: every cases except 3 cases above this line.
  	{
  		if(numbers[0] <= numbers[1])
  		{
  			min = numbers[0];
  		}
  		else
  		{
  			min = numbers[1];
  		}

    		for(i = 2; numbers[i] != '\0'; i++)
    		{
    			if(min <= numbers[i])
    			{

    			}
    			else
    			{
    				min = numbers[i];
    			}
    		}
    	}

  	return min; // Return value of min.
}