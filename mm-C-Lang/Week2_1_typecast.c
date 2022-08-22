
#include <stdio.h>
#pragma warning(disable:4996)



int main_2_1_3()
{
    unsigned char  num = 20;
	int bigNum = 1000 ;
	// implicit
	bigNum = num;
	// explicit
	num = (char) bigNum;

	 bigNum = num;
	// type cast 
	num = (char) bigNum;

}