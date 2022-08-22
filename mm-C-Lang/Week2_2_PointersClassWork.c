
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)
// function specification 
// function body
int* alloc5Numbers(int num1, int num2, int num3, int num4, int num5);
int printNum(int* numberList);

int main_2_6_2()
{
	int* address = alloc5Numbers(2, 3, 4, 5, 6);
	int sum = printNum(address);
	free(address);

	for (int i = 0; i < 1000; i++)
	{
		address = malloc(1000000);
		free(address);
	}

	return 0;
}

int printNum(int* numberList)
{
	int sum = 0;
	int* ptr = numberList;
	for (int i = 0; i < 5; i++)
	{
		// sum+=3     sum=sum+3
		sum += *ptr;
		ptr++;
	}

	return sum;

}
int* alloc5Numbers(int num1, int num2, int num3, int num4, int num5)
{
	int* ret;
	int* original;
	ret = malloc(5 * sizeof(int));
	original = ret;

	if (ret == NULL)
	{
		// no memory alocation
		// error message
	}
	else
	{
		*ret = num1;
		ret++;

		*ret = num2;
		ret++;

		*ret = num3;
		ret++;

		*ret = num4;
		ret++;

		*ret = num5;

	}
	return original;
}

