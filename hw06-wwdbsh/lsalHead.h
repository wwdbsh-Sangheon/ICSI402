#define MAX 255

int findIndentation(DIR* dp, struct dirent* entry, struct stat buf, char* path, char* dir, int max, int low, int i); // Prototypes
void readDirectory(DIR* dp, DIR* dp2, DIR* dp3, char* path);
void accessAuthority(struct stat buf);
int sort(const void* a, const void* b);

void readDirectory(DIR* dp, DIR* dp2, DIR* dp3, char* path)
{
 	struct dirent *entry, *entry2, *entry3; // Declaring struct dirent pointer type variables.
	struct passwd* pw; // struct passwd pointer type variable.
	struct group* group; // struct group pointer type variable.
	struct stat buf; // struct stat variable.
	char tstr[MAX], dir[MAX], dName[MAX][MAX]; // Declaring both one and two dimensional array type variables.
	int sL, lL, flag = 0, sMax = 0, lMax = 0, total = 0, i = 0, i2 = 1, j = 0; // int type vaiables.

	while((entry = readdir(dp)) != NULL) // Loop for getting total block size and storing d_name into array.
	{
		strcpy(dir, path);
		strcpy(dName[j], entry->d_name); // Storing d_name into dName array.
		strcat(strcat(dir, "/"), dName[j]);
		lstat(dir, &buf);
		total += buf.st_blocks; // Increasing total by adding buf.st_blocks.
		j++; // Increasing j by adding 1.
	}

	qsort(dName, j, MAX, sort); // Sorting array elements.
	printf("total %d\n", total); fflush(stdout); // Printing out total block size.

	while(flag < j) // Loop for printing out output values
	{
		strcpy(dir, path);
		strcat(strcat(dir, "/"), dName[flag]);
		lstat(dir, &buf);

		if(flag == 0) // Condition: flag is 0.
		{
			lMax = findIndentation(dp2, entry2, buf, path, dir, lMax, lL, i); // Value of indentation for the number of links
			sMax = findIndentation(dp3, entry3, buf, path, dir, sMax, sL, i2); // Value of indentation for size
		}

		pw = getpwuid(buf.st_uid); // Value for owner name
		group = getgrgid(buf.st_gid); // Value for group name
		sprintf(tstr, "%s", ctime(&buf.st_mtime)); // Storing date and time into tstr array.
		accessAuthority(buf); // Call accessAuthority function.
		printf("  %*d %s %s  %*d %.12s ", lMax, buf.st_nlink, pw->pw_name, group->gr_name, sMax, buf.st_size, tstr+4); fflush(stdout);
		printf("%s\n", dName[flag]); fflush(stdout);
		flag++; // Increasing flag by adding 1.
	}
 }

void accessAuthority(struct stat buf)
{
	S_ISDIR(buf.st_mode) ? printf("d") : printf("-"); fflush(stdout); // Directory
	buf.st_mode & S_IRUSR ? printf("r") : printf("-"); fflush(stdout); // Owner
	buf.st_mode & S_IWUSR ? printf("w") : printf("-"); fflush(stdout);
	buf.st_mode & S_IXUSR ? printf("x") : printf("-"); fflush(stdout);
	buf.st_mode & S_IRGRP ? printf("r") : printf("-"); fflush(stdout); // Group
	buf.st_mode & S_IWGRP ? printf("w") : printf("-"); fflush(stdout);
	buf.st_mode & S_IXGRP ? printf("x") : printf("-"); fflush(stdout);
	buf.st_mode & S_IROTH ? printf("r") : printf("-"); fflush(stdout); // Others
	buf.st_mode & S_IWOTH ? printf("w") : printf("-"); fflush(stdout);
	buf.st_mode & S_IXOTH ? printf("x") : printf("-"); fflush(stdout);
}

int findIndentation(DIR* dp, struct dirent* entry, struct stat buf, char* path, char* dir, int max, int low, int i)
{
	int j = 0; // Initializing j to 0.

	while(((entry = readdir(dp)) != NULL)) // Loop for finding max value
	{
		strcpy(dir, path);
		strcat(strcat(dir, "/"), entry->d_name);
		lstat(dir, &buf);
		i == 0 ? (low = buf.st_nlink) : (low = buf.st_size); // Condition: i is 0.
		max < low ? (max = low) : (max = max); // Condition: max is less than low.
	}

	for( ; max != 0; max /= 10) j++; // Loop for getting indentation.

	return j;
}

int sort(const void* a, const void* b) // Function for qsort function
{
	return strcasecmp(a, b); // it allows qsort function to ignore case sensitivity.
}