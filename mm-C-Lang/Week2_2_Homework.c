
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)



unsigned char TurnOnBitAndPrint(unsigned char aByte)
{
	// 4
	// 00001000

	return (unsigned char)0;
}



unsigned char  mirrorPrintByte(unsigned char num)
{
	// 4 - 00000100

	unsigned char proccedNum = num;
	//   111111100
	unsigned char mask = 0b00000001;
	for (int i = 0; i < 8; i++)
	{
		char oneBit = proccedNum & mask;
		proccedNum = proccedNum >> 1;
		printf("%d", oneBit);
	}

	return  (unsigned char) 0;
} 



unsigned char  aPrintByte(unsigned char num)
{
	mirrorPrintByte(mirrorPrintByte(num));
}



int main_2_4_5()
{
	aPrintByte((unsigned char)4);
	//00001000
}