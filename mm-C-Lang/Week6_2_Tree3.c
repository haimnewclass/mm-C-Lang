
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


typedef struct Leaf
{
	// Management or MetaData
	int level;
	struct Leaf* Left;
	struct Leaf* Right;
	struct Leaf* Parent;

	// Data (Real Data)
	int Val;
} TLeaf;
TLeaf* Root;

void AddLeaf(TLeaf* curr, int val)
{
	TLeaf* newLeaf = (TLeaf*)malloc(sizeof(TLeaf));
	newLeaf->Val = val;
	newLeaf->Right = NULL;
	newLeaf->Left = NULL;

	if (Root == NULL)
	{
		Root = newLeaf;
		newLeaf->Parent = NULL;
	}
	else {
		if (curr == NULL)
		{
			curr = Root;
		}

		if (curr->Val < val)
		{
			if (curr->Right == NULL)
			{
				// add into
				curr->Right = newLeaf;
				newLeaf->Parent = curr;
			}
			else
			{
				AddLeaf(curr->Right, val);
			}
			
		}
		else
		{
			if (curr->Left == NULL)
			{
				// add into
				curr->Left = newLeaf;
				newLeaf->Parent = curr;
			}
			else
			{
				AddLeaf(curr->Left, val);
			}
		}
	
	}
}

main()
{
	Root = NULL;
	AddLeaf(NULL, 3);
	AddLeaf(NULL, 9);
	AddLeaf(NULL, 4);
	AddLeaf(NULL, 2);
	AddLeaf(NULL, 223);
	AddLeaf(NULL, 23);
	AddLeaf(NULL, 5);
	AddLeaf(NULL, 123);
	AddLeaf(NULL, 322);
	AddLeaf(NULL, 10);
	AddLeaf(NULL, 100);

	PrintTree();
}
