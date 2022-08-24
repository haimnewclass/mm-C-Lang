
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_2_3_4()
{
	char* fileName = "c:\\a\\data.txt";
	char* relativeFileName = "data.txt";

	char* str;
	str = malloc(100);
	strcpy(str, "c:\\a\\data.txt");

	// r - open for reading
	// w - open for writing (override already existed data)
	// a - open for append to end of file

	FILE* f = fopen(relativeFileName, "a");

	if (f != NULL)
	{
		fputc('a', f);
		fputc('b', f);
		fputc('c', f);
		fputc('\n', f);
		fputc('1', f);
		fputc('2', f);
		fputc('3', f);
		fputc('\n', f);
	}
	else
	{
		// error
		f = fopen(relativeFileName, "r");
		if (f != NULL)
		{

		}
	}
	fclose(f);

}