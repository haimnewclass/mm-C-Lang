#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#pragma warning(disable:4996)


#define SEPERATOR "[[[LINE1]]]"


int SaveIntoFile(char* fileName,char *buff)
{
	FILE* fi = fopen(fileName, "w");
	if (!fi)
	{
		return 0;
	}

	fputs(buff, fi);

	 
	fclose(fi);
}
char* ReadAllFile(char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		return NULL;
	}


	// Get the file size
	char* buff = (char*)malloc(1000);
	char* read;
	int fileSize = 0;
	while ((read = fgets(buff, 1000, f)))
	{
		fileSize += strlen(buff);
	}

	free(buff);
	fclose(f);

	// alloc space as file size
	buff = (char*)malloc(fileSize);

	f = fopen(fileName, "r");
	if (!f)
	{
		return NULL;
	}
	int readPosition=0;
	char charToRead;
	while ((charToRead = fgetc(f))!=EOF)
	{
		buff[readPosition] = charToRead;
		readPosition++;
	}
	buff[readPosition] = NULL;

	fclose(f);

	return buff;
}

int main()
{



	char HTML_REPLACE[]= "<div>HAIM</div>";
	char* htmlTemplate = ReadAllFile("C:\\Users\\ASI\\source\\repos\\mm-C-Lang\\mm-C-Lang\\Test.html");

	char* found = strstr(htmlTemplate, SEPERATOR);
	
	int len = found - htmlTemplate;
	char* newBuff = (char*)malloc(strlen(htmlTemplate)+strlen(HTML_REPLACE));

	strncpy(newBuff, htmlTemplate,len);
	newBuff[len] = NULL;



	strcat(newBuff, HTML_REPLACE);

	newBuff[len+strlen(HTML_REPLACE)] = NULL;

	strcat(newBuff, found + strlen(SEPERATOR));

	SaveIntoFile("newTest.html", newBuff);


	free(newBuff);
	free(htmlTemplate);

	return 0;
}
