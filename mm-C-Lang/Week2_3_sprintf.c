#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_3_100()
{
	char str1[100];
	char str2[200] = "Abanibioboebe";

	sprintf(str1, "TheFormat%d%s%d%s", 234, str2, 2 + 2, "maoz");

	printf("%s", str1);
}