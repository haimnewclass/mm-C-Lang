
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
#include "Week4_3_UseFunc.h"


int Biggets(int a, int b)
{
	struct item k;
	if (a > b)
		return a;
	else
		return b;
}


int main_4_3_234()
{
	int g = Biggets(3, 5);
	return 0;
}