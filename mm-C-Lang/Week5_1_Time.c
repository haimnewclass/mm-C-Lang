
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

main()
{
	
	/*
	2022.11.01:233443 - Event - System is starting
	2022.11.01:233444 - Error - File Is Not opened
	2022.11.01:233445 - Event - System is ending
	*/
	time_t t;
	time(&t);

	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char str[100];
	 
	sprintf(str, "%d%d%d", timeinfo->tm_year, timeinfo->tm_mon, timeinfo->tm_yday);
}