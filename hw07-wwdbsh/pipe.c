#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char*** make3DArray(char*** arr, int row, int col); // Prototypes
char*** make2DArrays(char*** arr, char* args[], int count);
char** makeLast2DArray(char** arr, char* args[], int i);
void showErrorMSG(int num, char* args[]);
void makePipe(int fd[], int count);
void closePipe(int fd[], int count);
void waitChildren(int c_status, int count);
void startPipe(char*** buffer, int fd[], int count, int w, int r, int i);
void free3DArray(char*** buffer, int row, int col);
int findPipeline(int count, int num, char* args[]);

int main(int argc, char* argv[])
{
	char*** buffer = NULL; // Initializing 3 dimensional type variable.
	int count = 0, c_status; // Declaring count and status as int.
	
	showErrorMSG(argc, argv); // Showing error message.
	count = findPipeline(count, argc, argv); // Finding the number of "@"
	buffer = make3DArray(buffer, count+1, argc-1); // Allocating memory to buffer.
	
	int fd[2*count]; // Deciding the number of fd[2].

	if(count == 0) // Condition: no @
	{
		buffer[count] = makeLast2DArray(buffer[count], argv, 1); // Making last element of 3D array.
		execvp(buffer[0][0], buffer[0]); // Call execvp.
	}

	buffer = make2DArrays(buffer, argv, count); // Making all elements of 3D array.
	makePipe(fd, count); // Making pipe line(s).
	startPipe(buffer, fd, count, 1, 0, 0); // Executing linux commands and pipe lines.
	waitChildren(c_status, count); // Waiting children's process.
	free3DArray(buffer, count+1, argc-1); // Free All memory.
	
	return 0;
}

char*** make3DArray(char*** arr, int row, int col)
{
	int i;

	arr = (char***)malloc(row*sizeof(char**)); // Allocating memory for 3D

	for(i = 0; i < row; i++)
		arr[i] = (char**)malloc(col*sizeof(char*)); // Allocating memory for 2D

	return arr; // return arr.
}

char*** make2DArrays(char*** arr, char* args[], int count)
{
	int i, j, k = 1;
		
	for(i = 0; i <= count; i++)
	{
		if(i < count) // Condition: i is less than count.
		{
			for(j = 0; strcmp(args[k], "@") != 0; j++)
			{
				arr[i][j] = args[k];
				arr[i][j+1] = NULL;
				k++;
			}
			k++;
		}
		else
		{
			arr[count] = makeLast2DArray(arr[count], args, k); // Making last element of 3D array.
		}
	}

	return arr; // Return arr.
}

char** makeLast2DArray(char** arr, char* args[], int i)
{
	int j = 0;

	for( ; args[i] != NULL; i++)
	{	
		arr[j] = args[i];
		arr[j+1] = NULL;
		j++;
	}

	return arr; // Return arr.
}

void showErrorMSG(int num, char* args[])
{
	if(num == 1) // Condition: num is equal to 1.
	{
		fprintf(stderr, "Usage: pipe cmd cmd-arg1 ... [ @ cmd cmd-arg1 ...]\n"); fflush(stdout);
		exit(1);
	}
	
	if((strcmp(args[1], "@") == 0) || (strcmp(args[num-1], "@") == 0)) // Condition: Either args[1] or args[num-1] is "@".
	{
		fprintf(stderr, "pipe: syntax error near '@'\nUsage: pipe cmd cmd-arg1 ... [ @ cmd cmd-arg1 ...]\n"); fflush(stdout);
		exit(1);
	}
}

void makePipe(int fd[], int count)
{
	int i;

	for(i = 0; i < 2*count; i+= 2)
	{
		if(pipe(fd+i) == -1) // Making pipe line.
		{
			perror("Pipe failed");
			exit(1);
		}
	}
}

void closePipe(int fd[], int count)
{
	int i;

	for(i = 0; i < 2*count; i++) close(fd[i]); // Closing multiple pipe by using loop.
}

void waitChildren(int c_status, int count)
{
	int i;

	for(i = 0; i < count+1; i++) wait(&c_status); // Waiting multiple child processes by using loop.
}

void startPipe(char*** buffer, int fd[], int count, int w, int r, int i)
{
	if(fork() == 0) // Condition: fork() returns 0.
	{
		if(i > 1) // Condition: i is greater than 1.
		{
			dup2(fd[r], 0);
		}
		else if(i <= 1 && i != 0) // Condition: i is equal or less than 1, and i is not 0.
		{
			dup2(fd[r], 0);
		}

		dup2(fd[w], 1);

		closePipe(fd, count); // Closing pipe line(s).
		execvp(buffer[i][0], buffer[i]); // Call execvp.
	}
	else
	{
		i += 1;

		if(i > 1) r += 2; // Condition: i is greater than 1.

		if(i == count) // Condition: i is equal to count.
		{
			dup2(fd[r], 0);
			closePipe(fd, count); // Closing pipe line(s).
			execvp(buffer[count][0], buffer[count]); // Call execvp.
		}
		else
		{
			w += 2;
			startPipe(buffer, fd, count, w, r, i); // Calling by itself.
		}
	}
}

void free3DArray(char*** buffer, int row, int col) // Free memory.
{
	int i, j;

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			free(buffer[i][j]);
			buffer[i][j] = NULL;
		}
		free(buffer[i]);
		buffer[i] = NULL;
	}
	free(buffer);
	buffer = NULL;
}

int findPipeline(int count, int num, char* args[])
{
	int i;

	for(i = 2; i < num; i++)
	{
		if(strcmp(args[i], "@") == 0) count++; // Condition: args[i] is "@"
	}

	return count; // return count.
}