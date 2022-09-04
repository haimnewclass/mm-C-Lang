
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
 

int main_4_1_80(int argc, char* argv[])
{

 

	//printf("Start \n");
	//printf("%d %s %s %s ", argc, argv[0], argv[1], argv[2]);
	int a ;
	int b ;
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d+%d=%d \n",a,b,a+b);
	 
	printf("Program Was Done \n");
	

	return 0;
}