#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 255

int main(int argc, char* argv[])
{
	FILE* file; // Declaring FILE pointer type variable.

	int i = 0; // Int type variable for line numbers.
	char line[MAX]; // char array variable.

	if(argc < 3 || argc > 3) // Condition: If the number of arguements is not 3, print error message.
	{
		fprintf(stderr, "Usage: filegrep PATTERN FILE\n"); fflush(stdout);	
	}
	else
	{
		if((file = fopen(argv[2], "r")) != NULL) // Condition: If input file does not exist, print error message.
		{
			while(fgets(line, MAX, file) != NULL) // Getting line from input file, and storing it into variable line.
			{
				i++; // Increasing i by adding 1.

				if(strstr(line, argv[1]) != NULL) // Searching pattern which is argv[1] in line.
				{
					if(strchr(line, '\n') == NULL) strcat(line, "\n"); // For last line.
					printf("%d:%s", i, line); fflush(stdout); // printing line and line number.
				}
			}

			if(fclose(file) == EOF) // Closing file.
			{
				fprintf(stderr, "Error in closing file.\n"); fflush(stdout);
			}
		}
		else
		{
			fprintf(stderr, "Usage: filegrep PATTERN FILE\n"); fflush(stdout);
		}
	}

	return 0;
}