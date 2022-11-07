#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#pragma warning(disable:4996)

int func111(char a)
{
	return a * a;
}
int func222(char a)
{
	return a + a;
}

char func333(int a, int b)
{
	return (char) b - a;
}

int calc(int g, int (*p)(char))
{
	return g + p(100);
}

static main()
{
	int r = func111(3);
	
	int (*p)(char);
	char (*p3)(int, int);

	p3 = &func333;
	//p3 = &func111; wrong

	p = &func222;
	p(2, 3);
	p = &func111;
	r = p(4);
	p = &func222;
	r = p(4);

	calc(200, &func111);
	calc(200, &func222);

}