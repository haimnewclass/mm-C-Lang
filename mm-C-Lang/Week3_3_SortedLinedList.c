
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


//typedef  char[1000] Data;


 
struct Item
{
	int Val;
	struct Item* Next;
	struct Item* Prev;
};

struct Item* Head = NULL;
struct Item* Tail = NULL;
void GenerateList();
struct Item* FindVal(int val);
struct Item* ChangeVal(int oldVal, int newVal);

int main_3_3_5()
{
	GenerateList();
	ChangeVal(100, 3);
}

void GenerateList(){

	struct Item* Curr;
	struct Item* Old=NULL;

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

struct Item* ChangeVal(int oldVal, int newVal) {

	struct Item* ret = FindVal(oldVal);
	if (ret != NULL)
	{
		ret->Val = newVal;
	}
}

struct Item* FindVal(int findVal)
{
	struct Item* ret = NULL;
	struct Item* Curr = Head;
	while (Curr!=NULL)
	{
		if (Curr->Val == findVal)
		{
			ret = Curr;
		}
		Curr = Curr->Next;
	}

	return ret;
}