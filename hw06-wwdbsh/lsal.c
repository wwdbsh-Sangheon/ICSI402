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
	DIR *dp, *dp2, *dp3; // Declaring DIR pointer types variables.
	char dir[MAX]; // Decalring char array type variable.
	
	if(argc != 1) // Condition: argc are not 1.
	{
		if((dp = opendir(argv[1])) == NULL) // Condition: Open directory and then it returns NULL.
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[1]); fflush(stdout); // Printing out error message.
			exit(1); // Exit program.
		}

		strcpy(dir,argv[1]); // Copying argv[1] to dir.
		dp = opendir(dir); // Open directory.
		dp2 = opendir(dir);
		dp3 = opendir(dir);
		readDirectory(dp, dp2, dp3, dir); // Call readDirectory function.
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