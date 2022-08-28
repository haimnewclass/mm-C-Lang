
#include <stdio.h>
#pragma warning(disable:4996)

int main2_1()
{

	int h = sizeof(int)*100;
	int d = 1;
	d = d << 31;
	d = d << 1;
	char num = 0b00000001;

	int a = 0;
	a++; a--;
	a += 10; // a = a+10;
	a -= 10; // a= a-10;


	num << 2;	
	unsigned char num2;
	unsigned int num5;

	num = num << 1;
	num <<= 4; // num = num << 4

	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;
	num = num << 1;

	num = -1;
	num = num >> 1;
	num = num >> 1;
	num = num >> 1;
	num = num >> 1;
	num = num >> 1;

	printf("%d", num);
	return 0;
}

