
#include <stdio.h>
 

#pragma warning(disable:4996)


int main()
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