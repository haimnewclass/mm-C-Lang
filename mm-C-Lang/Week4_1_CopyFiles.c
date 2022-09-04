
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

void testCopy(char* fileSrc, char* fileDest);

void testCopy(char* fileSrc, char* fileDest)
{
	// find out the file size
	int count;
	FILE* fsrc;
	FILE* fdest;
	char* memory;
	count = 0;
	int read = 0;
	char tmp;
	fsrc = fopen(fileSrc, "r");
	if (fsrc)
	{
		while ((read = fread(&tmp, sizeof(char), 1, fsrc)) > 0)
		{
			count = count + read;
		}
		fclose(fsrc);

		memory = (char*)malloc(count);
	}
	else
	{
		// error
		return;
	}


	// read all file into memory
	fsrc = fopen(fileSrc, "r");
	if (fsrc)
	{
		int readPackages = fread(memory, sizeof(char), count, fsrc);
		fclose(fsrc);
	}
	else
	{
		// error
		return;
	}

	// write all memory into file
	fdest = fopen(fileDest, "w");
	if (!fdest)
	{
		// error
		return;
	}
	else
	{
		fwrite(memory, sizeof(char), count, fdest);
		fclose(fdest);
		free(memory);
	}
}

int main_4_1_copy(int argc, char* argv[])
{


	//testCopy("c:\\a\\a3.txt", "c:\\a\\newFile.txt");
	testCopy(argv[1], argv[2]);

 


	return 0;
}