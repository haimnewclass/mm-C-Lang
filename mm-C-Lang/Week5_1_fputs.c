
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

main()
{
	FILE* f = fopen("myProg.log","w");

	fputs("line1\n", f);
	fputs("line2\n", f);
	fputs("line3\n", f);
	fclose(f);

	char str[100000];

	f = fopen("myProg.log", "r");

	// if null 
	 
	while (fgets(str, 100000, f) != NULL)
	{
		printf("%s", str);
	}
	
	fclose(f);



}