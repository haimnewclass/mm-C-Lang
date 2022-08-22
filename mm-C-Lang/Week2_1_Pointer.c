
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)



int main_2_2_5()
{
	 
	 
	int a = 90;
	int c = 88;
	int* b;
	
	b = &a;
	printf("%x\n", b);
	printf("%d\n", *b);

	a = 100;
	printf("%x\n", b);
	printf("%d\n", *b);

	b = &c;

	b = malloc(10 * sizeof(int));
	*b = 100;
	int* original = b;
	b++;
	*b = 200;

	char* charPtr;
	charPtr = b;
	charPtr++;
	*charPtr = 'A';
	 

	free(original);
	 
	return 0;
}
