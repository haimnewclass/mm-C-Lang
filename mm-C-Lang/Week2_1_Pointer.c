
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)



int main()
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
	b++;
	*b = 200;


	free(b);
	*b = 80;
}
