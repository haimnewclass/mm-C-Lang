
#include <stdio.h>
#pragma warning(disable:4996)


unsigned char  func2(unsigned char num)
{
	// 4 - 00000100

	unsigned char proccedNum = num;
					 //   111111100
	unsigned char mask = 0b10000000;
	for (int i = 0; i < 8; i++)
	{
		char oneBit = proccedNum & mask;
		proccedNum = proccedNum >> 1;
		printf("%d", oneBit);
	}


	return 0;
}


int main2_4()
{
	unsigned char  num= 0b10001110;
	func2(num);
}