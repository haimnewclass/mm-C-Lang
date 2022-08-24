

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_2_3_2()
{

	
	int* i;
	FILE* f;

	f = fopen("c:\\haim\\data.txt","r");
	if (f == NULL)
	{
		// problem
		// error message
	}
	else
	{
		char ch = fgetc(f);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(f);
		}

		fclose(f);
	 
	}
	
}

