
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

int main_3_2_1()
{
	struct Student
	{
		int age;
		char name[100];
		int classLevel;
	};

	struct Student s = {20,"Amos",1 };
	s.age = 21;

	FILE* f = fopen("oneStudent.dat", "w");

	if (f == NULL)
	{
		// error
	}
	else
	{
		fwrite(&s, sizeof(struct Student), 1, f);
		fclose(f);
	}
	//////////////////////////////////////////////////////

	/// Prepare memory

	struct Student* list;
	struct Student* currentStudent;

	int size = 4;
	currentStudent = malloc(sizeof(struct Student) * size);
	list = currentStudent;

	
	strcpy(currentStudent->name, "Matan");
	currentStudent->classLevel = 2;
	currentStudent->age = 30;
	currentStudent++;


	strcpy(currentStudent->name, "Amos");
	currentStudent->classLevel = 3;
	currentStudent->age = 22;
	currentStudent++;

	strcpy(currentStudent->name, "Amram");
	currentStudent->classLevel = 5;
	currentStudent->age = 24;
	currentStudent++;

	strcpy(currentStudent->name, "Yaacov");
	currentStudent->classLevel = 123;
	currentStudent->age = 120;


	/// Save Memory
	f = fopen("students.dat", "w");
	fwrite(list, sizeof(struct Student), size, f);
	fclose(f);

	// free
	free(list);
}