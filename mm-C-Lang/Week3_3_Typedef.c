
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_3_3_3()
{
	int a;

	



	typedef unsigned char CarCount;
	typedef char LastName[100];

	//structure of family
	typedef struct
	{
		LastName name;
		int members;
		int Pets;
		CarCount cars;
		char address[100];

	} Family_S;

	Family_S oneFamily;
	oneFamily.cars = 12;
	oneFamily.Pets = 1;

	struct StudentDetails
	{
		LastName name;
		char address[100];
		CarCount cars;
	};
	LastName userInsertName;
	char userInsertAddress[100];

}
