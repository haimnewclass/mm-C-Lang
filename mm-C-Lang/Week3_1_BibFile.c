#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_3_1_3()
{  // מרכז מעשה
	FILE* f;

	int a = 190;
	int b = 290;
	int c = 390;

	f = fopen("data.bin", "w");

	if (f == NULL)
	{
		// error

	}
	else
	{
		fwrite(&a, sizeof(int), 1, f);
		fwrite(&b, sizeof(int), 1, f);
		fwrite(&c, sizeof(int), 1, f);
		fclose(f);
	}

	FILE* f1 = fopen("data.bin", "r");
	if (f1 == NULL)
	{
		// error

	}
	else
	{
		int read = fread(&c, sizeof(int), 1, f1);
		printf("%d", c);
		read = fread(&c, sizeof(int), 1, f1);
		printf("%d", c);
		read = fread(&c, sizeof(int), 1, f1);
		printf("%d", c);
		fclose(f1);
	}


}