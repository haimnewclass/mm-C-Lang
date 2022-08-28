
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

 

#ifdef TARGIL
int getNum()
{

}
#endif

int main_3_1_12()
{
	 
	int arr[5] = { 23,44,56,100,1009 };
	int arr2[5];


	/// <summary>
	/// write array into file
	/// </summary>
	/// <returns></returns>
	FILE* f = fopen("array.ggg", "w");

	if (f == NULL)
	{
		// error
	}
	else
	{
		// arr = &arr[0]
		int written = fwrite(arr, sizeof(int), 5, f);
		fclose(f);
	}


	/// <summary>
	/// read array from file when you know the full size
	/// </summary>
	/// <returns></returns>
	/// 
	f = fopen("array.ggg", "r");

	if (f == NULL)
	{
		// error
	}
	else
	{
		// arr = &arr[0]
		int read = fread(arr2, sizeof(int), 5, f);
		fclose(f);
	}

	/// <summary>
	/// read from file when you dot know the array size
	/// </summary>
	/// <returns></returns>
	f = fopen("array.ggg", "r");

	//if (f != NULL)
	if(f)
	{
		int item;
		// arr = &arr[0]
		int read;
		//while ((read = fread(&item, sizeof(int), 1, f))>0)

		// 0 FALSE
		// !=0 TRUE
		// fread returns 0 when any byte was read
		while (fread(&item, sizeof(int), 1, f))
		{
			printf("%d", item);
		}
		fclose(f);
	}
	else
	{
		// Error
	}

}
 

