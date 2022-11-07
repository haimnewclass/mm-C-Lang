#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#pragma warning(disable:4996)

int main()
{
	char str[10000];
	int s = sprintf(str, "%s-%s","abcdefg", "123134");

	s = sprintf(NULL, "%s-%s", "abcdefg", "123134");

	char* p = malloc(s * sizeof(char));
	sprintf(p, "%s-%s", "abcdefg", "123134");
	p[3] = 'd';
	p++;

}