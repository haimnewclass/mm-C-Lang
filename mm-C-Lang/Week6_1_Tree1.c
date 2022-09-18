
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

typedef struct
{
	int age;
} DetailsT;

typedef struct Leaf
{
	// Management or MetaData
	int level;
	struct Leaf* Left;
	struct Leaf* Right;
	struct Leaf* Parent;

	// Data (Real Data)
	DetailsT Details;
} TLeaf;
struct Leaf* Root; 

typedef struct QueueItem {
	TLeaf *leaf;

	struct QueueItem* prev;
	struct QueueItem* next;

} TQueueItem;

TQueueItem *Queue_Head;
TQueueItem *Queue_Tail;

void Queue_Push(TLeaf* leaf)
{
	//malloc
}


void Queue_Status()
{

}


void Queue_Clear()
{

}

TQueueItem*  Queue_Pop()
{
	 
}

//////////////////////////////////////
void AddTreeItem(DetailsT item)
{
	// Add new item into Tree
	struct Leaf* newLeaf = (struct Leaf*)malloc(sizeof(struct Leaf));
	newLeaf->Details = item;

	newLeaf->Right = NULL;
	newLeaf->Left = NULL;
	
	if (Root == NULL)
	{
		newLeaf->Parent = NULL;
		Root = newLeaf;
		newLeaf->level = 0;
	}
	else if (Root->Right == NULL)
	{
		Root->Right = newLeaf;
		newLeaf->Parent = Root;
		newLeaf->level = 1;
	}
	else if (Root->Left == NULL)
	{
		Root->Left = newLeaf;
		newLeaf->Parent = Root;
		newLeaf->level = 1;
	}


}


void BuildTree()
{
	for (int i = 0; i < 100; i++)
	{
		DetailsT* details = (DetailsT*)malloc(sizeof(DetailsT));
		details->age = i;

		AddTreeItem(*details);
	}
}

void FromQueueToTree()
{
	 
}

TLeaf* FindEmptyPlaceLeaf(TLeaf* leaf)
{
	if (leaf->Left != NULL)
		return leaf->Left;
	else if (leaf->Right != NULL)
		return leaf->Right;
	else
		return NULL;
}

main()
{
	Root = NULL;
	Queue_Tail = NULL;
	Queue_Head = NULL;

	BuildTree();
	struct Leaf leaf;
	struct Leaf *leafPtr = (struct Leaf* ) malloc(sizeof(struct Leaf));

	leaf.Details.age = 23;
	leafPtr->Details.age = 23;

	//strcpy(leaf.Details.address, "dafsdfsdf");
}