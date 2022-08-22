
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)



int main()
{

	char tt = 0b10000000;
	char t1 = -12;
	char t3 = tt & t1;
	unsigned char t4 = t3 ^ 0b11111111;
	 
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
