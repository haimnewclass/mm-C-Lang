
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


struct Item
{
	int Val;
	struct Item* Next;
	struct Item* Prev;
};
struct Item* Head = NULL;
struct Item* Tail = NULL;

 
int main()
{
}

void GenerateList(){

	struct Item* Curr;
	struct Item* Old;

	for (int i = 0; i < 10; i++)
	{
		Curr = (struct Item*) malloc(sizeof(struct Item));
		
		
		//TODO: Compleate the Random issue
		Curr->Val = 100;
		 

		if (Head == NULL)
		{
			Head = Curr;
			Tail = Curr;
			Curr->Next = NULL;
			Curr->Prev = NULL;
		}
		else
		{
			Tail = Curr;
			Curr->Next = NULL;
			Curr->Prev = Old;
			Old->Next = Curr;
			
		}
		Old = Curr;
	}
}