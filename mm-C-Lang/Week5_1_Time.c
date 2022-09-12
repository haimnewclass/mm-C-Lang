
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

main5_1_time()
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

void Log(char message[100])
{
	FILE* f = fopen("MyApp.log", "a");
	fputs(message,f);
	fclose(f);
}

void ErrorLog(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Error - %s", message);
	Log(newMessage);
}


void EventLog(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Event - %s", message);
	Log(newMessage);
}