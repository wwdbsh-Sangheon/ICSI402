#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<dirent.h>
#include<time.h>
#include "lsalHead.h"

int main(int argc, char* argv[])
{
	DIR *dp, *dp2, *dp3;
	char dName[MAX][MAX], dir[MAX];
	int i = 1, j = 0, k = 0;

	if(argc == 2) // Condition: argc are not 1.
	{	
		if((dp = opendir(argv[i])) == NULL) // Condition: Open directory and then it returns NULL.
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[1]); fflush(stdout); // Printing out error message.
			exit(1); // Exit program.
		}

		strcpy(dir,argv[i]); // Copying argv[i] to dir.
		dp = opendir(dir); // Open directory.
		dp2 = opendir(dir);
		dp3 = opendir(dir);
		readDirectory(dp, dp2, dp3, dir); // Call readDirectory function.
	}
	else if(argc > 2) // Condition: argc is greater than 2.
	{
		while(argv[i] != NULL)
		{
			if((dp = opendir(argv[i])) == NULL) // Condition: Open directory and then it returns NULL.
			{
				fprintf(stderr, "%s: No such file or directory\n", argv[i]); fflush(stdout); // Printing out error message.
			}
			else
			{
				strcpy(dName[j], argv[i]); // Copying argv[i] to dName[j].
				j++;
			}
			i++;
		}

		qsort(dName, j, MAX, sort); // Sorting array elements.

		while(k < j)
		{
			strcpy(dir, dName[k]); // Copying dName[k] to dir.
			printf("%s:\n", dir); fflush(stdout);
			dp = opendir(dir); // Open directory.
			dp2 = opendir(dir);
			dp3 = opendir(dir);
			readDirectory(dp, dp2, dp3, dir); // Call readDirectory function.
			if(k + 1 != j) printf("\n"); // Printing out \n except last line.
			k++;
		}
	}
	else
	{
		strcpy(dir, "."); // Copying . to dir.
		dp = opendir(dir);
		dp2 = opendir(dir);
		dp3 = opendir(dir);
		readDirectory(dp, dp2, dp3, dir);
	}

	return 0;
}
