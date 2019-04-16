#include <stdio.h>

void swap(int* arr, int a, int b); // Prototype

// permute_array function
int permute_array(int* arr, size_t len)
{
	unsigned int i; // Declaring i as an unsigned int.
	int tmp; // Delaring tmp as an int.

	for(i = 0; i < len; i++) // Loop for non-positive numbers including 0.
	{
		if(arr[i] <= 0)
		{
			swap(arr, 0, i); // Call swap function.
			break; // Break loop.
		}
	}

	if(arr[0] > 0)
	{
  		if(arr[1] == '\0') // Case: array has one value.
  		{
  			arr[0] = arr[0];
  		}
		else if(arr[2] == '\0') // Case2: array has two values.
  		{
			if(arr[0] <= arr[1])
  			{
  				arr[0] = arr[0];
  			}
 			else
  			{
  				swap(arr, 0, 1); // Call swap function.
  			}
  		}
		else // Case3: array has values more than 2.
		{
			if(arr[0] <= arr[1])
			{
				arr[0] = arr[0];
			}
			else
			{
				swap(arr, 0, 1); // Call swap function.
			}

  			for(i = 2; i < len; i++)
  			{
  				if(arr[0] <= arr[i])
  				{
  					arr[0] = arr[0];
  				}
  				else
  				{
  					swap(arr, 0, i); // Call swap function.
  				}
  			}
		}
	}

	return arr[0]; // Return arr[0].
}

// swap function
void swap(int* arr, int a, int b)
{
	int tmp;

	tmp = arr[a];
 	arr[a] = arr[b];
 	arr[b] = tmp;
}