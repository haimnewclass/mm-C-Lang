
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


struct Item {
	int val;
	int val2;
	int id;
	struct Item* next ;
	struct Item* prev ;
};

struct Item* Head;
struct Item* Tail;
int ID = 0;

void PrintList()
{

}
void AddItemToHead(int val, int val2)
{
	struct Item* newItem = malloc(sizeof(struct Item));
	newItem->id = ID;
	newItem->val = val;
	newItem->val2 = val2;
	
	Head = newItem;
	if (Head == NULL)
	{
		Tail = newItem;
	}
	else
	{
		Head->prev = newItem;
	}
	newItem->next = NULL;
	newItem->prev = Head;


}

struct Item* RemoveItemFromTail()
{

}
int main_4_1_()
{
	Head = NULL;
	Tail = NULL;
	ID = 0;
}