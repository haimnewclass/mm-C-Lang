
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

struct OskarActor
{
	int Index;
	int Year;
	char Age;
	char Movie[1000];
	char Name[1000];
	struct OskarActor* next;
	struct OskarActor* prev;
};


main_5_4_parse()
{
	//123,42545,23,44,123,3,3,4
	char str[100] = "aaa*bbb*ccc";
	char str2[100] = "123,456,789";
	char* token = strtok(str, "*");
	token = strtok(str2, ",");
	while (token != NULL)
	{
		printf("%s", token);
		token = strtok(NULL, ",");
	}

}