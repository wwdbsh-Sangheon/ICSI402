#include <stdio.h>
#include <stdlib.h>
#define NUMBER_COUNT_MAX 100

size_t read_numbers(int numbers[], size_t n) {
  unsigned int i = 0;

  /* note that in Linux you can signal end of file/stream by key combination ctrl-d */
  /*This 'while' code has a function for counting the number of input values which users
  entered and stores input values in the array int numbers[]. Users can enter integer
  values up to 100 times. If users entered values 100 times, the program will stop
  itself automatically. Otherwise, users can use ctrl-d to stop the program. After it,
   main function stores the value which is from read_numbers in variable 'numberlen.'
   And then, the program prints out 'numberlen' and sum of array elements by using
   'for' loop.
  */
  while (i < n && scanf("%d", &numbers[i]) != EOF) {
    i++;
  }

  return i;
}

int main(int argc, char *argv[]) {
  int numbers[NUMBER_COUNT_MAX];
  size_t numberlen;
  int i, sum;

  numberlen = read_numbers(numbers, NUMBER_COUNT_MAX);
  for (sum = 0, i = 0; i < numberlen; sum += numbers[i], i++);
  printf("read %d integers, total: %d\n", numberlen, sum);

  return 0;
}
