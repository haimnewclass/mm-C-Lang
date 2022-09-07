
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

typedef struct s_item {
	int key;
	int val;
	struct s_item* next;
	struct s_item* prev;

} t_Item;

// sample for creating instance of typedef vs struct
struct s_item s;
t_Item s1;

typedef struct {
	int version;
	int serialNum;
	int ItemsCount;
	char reserve[100];
} t_headerFile;

t_Item* Head;
t_Item* Tail;

t_Item* NewItem(int val,int key)
{
	t_Item* ret = (t_Item * ) malloc(sizeof(t_Item));
	ret->key = key;
	ret->val = val;
	ret->next = NULL;
	ret->prev = NULL;

	if (Head == NULL)
	{
		Head = ret;
		Tail = ret;
	}
	else
	{
		ret->prev = Tail;
		Tail->next = ret;
		Tail = ret;
	}
	return ret;
}

main()
{
	// init
	Head = NULL;
	Tail = NULL;


	// crearte 10 items
	for (int i = 0; i < 10; i++)
	{
		NewItem(i * 100, i);
	}

	t_headerFile fileHeader;
	fileHeader.version = 1;
	fileHeader.ItemsCount = 10;
	fileHeader.serialNum = 12345;

	// save in file
	FILE* f = fopen("Data.bin", "w");
	if (!f)
	{
		// error
		return 1;
	}

	fwrite(&fileHeader, sizeof(t_headerFile), 1, f);
	t_Item* curr = Head;
	while (curr != NULL)
	{
		fwrite(curr, sizeof(t_Item), 1, f);
		curr = curr->next;
	}
	
	fclose(f);

	// read from file

	// build the list


	curr = Head;
	while (curr != NULL)
	{		 
		curr = curr->next;
		free(Head);
		Head = curr;
	}

	return 0;
}

