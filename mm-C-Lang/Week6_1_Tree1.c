
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

  
main_6_1_1()
{
	Root = NULL;
	Queue_Tail = NULL;
	Queue_Head = NULL;

 	struct Leaf leaf;
	struct Leaf *leafPtr = (struct Leaf* ) malloc(sizeof(struct Leaf));

	leaf.Details.age = 23;
	leafPtr->Details.age = 23;

	//strcpy(leaf.Details.address, "dafsdfsdf");
}