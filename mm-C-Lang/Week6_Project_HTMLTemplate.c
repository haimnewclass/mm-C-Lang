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
	fileSize++;
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

#undef MAIN_HTML_GENERATION
#ifdef MAIN_HTML_GENERATION
int main()
{

	char HTML_REPLACE[]= "<div>HAIM</div>";
	char* htmlTemplate = ReadAllFile("C:\\Users\\ASI\\source\\repos\\mm-C-Lang\\mm-C-Lang\\Test.html");


	// find the token
	char* found = strstr(htmlTemplate, SEPERATOR);
	
	int len = found - htmlTemplate;
	char* newFileSpace = (char*)malloc(strlen(htmlTemplate)+strlen(HTML_REPLACE));

	strncpy(newFileSpace, htmlTemplate,len);
	newFileSpace[len] = NULL;

	strcat(newFileSpace, HTML_REPLACE);
	newFileSpace[len+strlen(HTML_REPLACE)] = NULL;

	strcat(newFileSpace, found + strlen(SEPERATOR));

	SaveIntoFile("newTest.html", newFileSpace);


	free(newFileSpace);
	free(htmlTemplate);

	return 0;
}
#endif
