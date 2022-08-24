#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_2_3_1()
{

	char ch = '7';
	char str[2];
	str[0] = ch;
	str[1] = NULL;



	char* str1 = malloc(100 * sizeof(char));
	char* root;
	root = str1;
	*str1 = 'S';
	str1++;
	*str1 = 'U';
	str1++;
	*str1 = NULL;
	int l = strlen(root);
	str1 = str1 + 5;
	strcpy(str1, root);
	strcpy(str1, "1234567890");
	str1 = str1--;
	strcpy(str1, root);

	free(root);
}