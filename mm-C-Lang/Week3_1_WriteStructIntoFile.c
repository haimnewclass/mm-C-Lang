#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_3_1_5()
{
	FILE* f;
	struct student
	{
		char name[100];
		int age;
	};
	 

	f = fopen("struct.bin", "w");

	struct student stu;
	strcpy(stu.name, "Shlomi");
	stu.age = 18;

	if (f == NULL)
	{
		// error

	}
	else
	{
		fwrite(&stu, sizeof(struct student), 1, f);
		fclose(f);
	}


	struct student newStu;

	f = fopen("struct.bin", "r");
	if (f == NULL)
	{
		// error
	}
	else
	{
		int read = fread(& newStu, sizeof(struct student), 1, f);
		fclose(f);
	}
	 
	return 0;
}