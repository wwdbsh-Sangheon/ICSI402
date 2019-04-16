#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXLEN 10

// Struct for pointer variable.
struct Chmod
{
  char array[MAXLEN];
};

int finding_octal(struct Chmod* rwx); // Prototype

// Main function
int main(void)
{
  int sum; // Int varialbe

  struct Chmod *rwx; // Pointer variable
  
  scanf("%s", rwx->array); // Get input value from stdin.
  sum = finding_octal(rwx); // Call finding_octal function and Store return value in sum.

  if(sum != 8 && rwx->array[MAXLEN - 1] == '\0') // When sum is not 8 and the last element array is \0, print out numbers. Otherwise, print out invalid permission
  {
    if(sum == 0) // Case: sum is 0
    {
      printf("000\n");
    }
    else if(sum < 10 && sum > 0) // Case: sum is less than 10 and is greater than 0.
    {
      printf("%d%d%d\n", 0, 0, sum);
    }
    else if(sum < 100) // Case: sum is less than 100.
    {
      printf("%d%d\n", 0, sum);
    }
    else // Case: every cases except 3 cases above this line.
    {
      printf("%d\n", sum);
    }
  }
  else
  {
    printf("invalid permission\n");
  }

  return 0;
}

// finding_octal function
int finding_octal(struct Chmod* rwx)
{
  int i, d, n = 0, e = 0, sum = 0;

  for(i = 0; i <= 6; i += 3) // loop for separating input value
  {
    if(((rwx->array[i] == 'r') || (rwx->array[i] == '-')) && ((rwx->array[i+1] == 'w') || (rwx->array[i+1] == '-')) && ((rwx->array[i+2] == 'x') || (rwx->array[i+2] == '-')))
    {
      if(rwx->array[i] == 'r') // If input value gets 'r' in i-th space, 4 is added to n.
      {
        n += 4;
      }

      if(rwx->array[i+1] == 'w') // If input value gets 'w' in i+1-th space, 2 is added to n.
      {
        n += 2;
      }

      if(rwx->array[i+2] == 'x') // If input value gets 'x' in i+2-th space, 1 is added to n.
      {
        n += 1;
      }

      if((rwx->array[i] == '-') || (rwx->array[i+1] == '-') || (rwx->array[i+2] == '-')) // If input value gets '-' in i-th or i+1-th or i+2-th space, n will be itself. 
      {
        n = n;
      }

      d = (int)pow(10, 2 - e)*n; // Math function for making 100, 10, and 1.
      sum += d; // d is added to sum.
      n = 0; // Initializing n to 0.
      e++; // Increasing e by adding 1.

    }
    else
    {
      sum = 8; // Counter value for 'if' statement on main function.
      break; // Break loop.
    }
  }

  return sum; // Return sum.
}

