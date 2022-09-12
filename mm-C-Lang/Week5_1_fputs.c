
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

main_5_1_2()
{
	FILE* f = fopen("myProg.log","w");
	/*
	2022.11.01:233443 - Event - System is starting
	2022.11.01:233444 - Error - File Is Not opened
	2022.11.01:233445 - Event - System is ending
	*/

	fputs("line1\n", f);
	fputs("line2\n", f);
	fputs("line3\n", f);
	fclose(f);

	char str[100000];

	sprintf(str, "%d %d %s", 23, 56 + 44, "Hi");
	

	f = fopen("myProg.log", "r");

	// if null 
	 
	while (fgets(str, 100000, f) != NULL)
	{
		printf("%s", str);
	}
	
	fclose(f);



}