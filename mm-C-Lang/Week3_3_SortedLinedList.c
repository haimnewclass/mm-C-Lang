
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

void LocateAfterTail(struct Item* item);
void LocateBeforeHead(struct Item* item);
void LocateBeforItem(struct Item* newItem, struct Item* itemInList);

typedef char BOOLEAN;

void GenerateList(){
	/*
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
	*/
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
//////////////////

struct Item*  findHigher(int val);

void AddItem( int newItem) {

	struct Item* Curr;


	 
	Curr = (struct Item*)malloc(sizeof(struct Item));


	//TODO: Compleate the Random issue
	Curr->Val = newItem;


	if (Head == NULL)
	{
		Head = Curr;
		Tail = Curr;
		Curr->Next = NULL;
		Curr->Prev = NULL;
	}
	else
	{



		struct Item* highItem =  findHigher(Curr->Val);
		// not found higher , means that new item is the smallest in list
		if (highItem == NULL)
		{
			LocateAfterTail(Curr);
		}
		else
		{
			if (highItem == Head)
			{
				LocateBeforeHead(Curr);
			}
			else
			{
				LocateBeforItem(Curr, highItem);
			}
		}



	}
	
	 
}

BOOLEAN isHaed(struct Item* item)
{
	return (item->Prev == NULL) ? 1 : 0;
}


BOOLEAN isTail(struct Item* item)
{
	return (item->Next == NULL) ? 1 : 0;
}

void LocateAfterTail(struct Item* item)
{
	item->Next = NULL;
	item->Prev = Tail;
	Tail->Next = item;
	Tail = item;
}


void LocateBeforeHead(struct Item* item)
{
	item->Next = Head;
	item->Prev = NULL;
	Head->Prev = item;
	Head = item;
}


void LocateBeforItem(struct Item* newItem, struct Item* itemInList )
{
	//itemInList->Prev->Next = newItem;
	struct Item* itemInList_prev = itemInList->Prev;
	itemInList_prev->Next = newItem;

	newItem->Prev = itemInList->Prev;
	newItem->Next = itemInList;
	itemInList->Prev = newItem;
	
}

struct Item* findHigher(int val) {

	struct Item* ret = NULL;
	struct Item* Curr = Head;
	while (Curr != NULL)
	{
		if (Curr->Val > val)
		{
			ret = Curr;
			return ret;
		}
		Curr = Curr->Next;
	}

	return ret;
 

}


int main_3_3_199()
{
	AddItem(7);
	AddItem(9);
	AddItem(8);
	AddItem(2);
	AddItem(3);
	AddItem(100);

	AddItem(5);


	GenerateList();
	ChangeVal(100, 3);
}
