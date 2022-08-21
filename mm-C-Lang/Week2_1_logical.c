
#include <stdio.h>
#pragma warning(disable:4996)

 
unsigned char  func1(unsigned char num, unsigned char moves)
{
	unsigned char ret = num << moves;
	return ret;
}


int main_2_2()
{
	int num1 = 10;
	int num2 = 20;

	if (num1 < num2 && num2 < 10 || num1 == 12)
	{

	}

	char a = 0b00000011;
	char b = 0b00000110;
	char c = a & b; //	  00000010
	c = a | b;		//	  00000111
	c = a ^ b;		//    

	int x = 0b0111010101;
	//0b0111010101;
	x = x ^ x;// xor itself reset the num

	unsigned char num3 = 2;
	unsigned char num4 = 2;

	printf("%d", func1(num3, num4));

	//
	// unsigned char num2 = 2 // 00000001
	// unsigned char num2 = 1 // 00000001
		 num3 = 0b00000011;
	char mask = 0b00000001; 
//			      00000010
			  //  00000001
	char maskResult = num3 & mask;

	printf("%d", maskResult);

	return 0;
}