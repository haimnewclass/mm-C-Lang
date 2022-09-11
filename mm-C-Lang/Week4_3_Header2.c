
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

#include "Week4_3_UseFunc.h"

#define FILE_NAME "Data3.bin"
#define Version 2


// sample for creating instance of typedef vs struct
struct s_item s;
t_Item s1;


t_Item* Head;
t_Item* Tail;

t_Item2* NewItem2(int val, int key,int id)
{
	t_Item2* ret = (t_Item2*)malloc(sizeof(t_Item2));
	ret->key = key;
	ret->val = val;
	ret->id = id;
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

main_5_1()
{
	
	// init
	Head = NULL;
	Tail = NULL;

	/*
	t_headerFile fileHeader;
	fileHeader.ItemsCount = 0;
	// crearte 10 items
	for (int i = 0; i < 10; i++)
	{
		NewItem2(i * 100, i);
		fileHeader.ItemsCount++;
	}


	fileHeader.version = Version;
	fileHeader.serialNum = 12345;

	// save in file
	FILE* f = fopen(FILE_NAME, "w");
	if (!f)
	{
		// error
		return 1;
	}

	// write the header into file
	fwrite(&fileHeader, sizeof(t_headerFile), 1, f);

	t_Item* curr = Head;
	//write all items into file
	while (curr != NULL)
	{
		fwrite(curr, sizeof(t_Item), 1, f);
		curr = curr->next;
	}

	fclose(f);

	// free memory
	curr = Head;
	while (curr != NULL)
	{
		curr = curr->next;
		free(Head);
		Head = curr;
	}

	*/


	// read from file
	FILE* f = fopen(FILE_NAME, "r");
	if (!f)
	{
		// error
		return 1;
	}

	t_headerFile headerOfFile;


	int read = fread(&headerOfFile, sizeof(t_headerFile), 1, f);
	if (read == 0)
	{
		// error
		return 1;
	}
	// build the list
	Head = NULL;
	Tail = NULL;

	if (headerOfFile.version == 1)
	{
		int id = 0;
		// Convert Process
		t_Item* curr;
		for (int i = 0; i < headerOfFile.ItemsCount; i++)
		{
			curr = (t_Item*)malloc(sizeof(t_Item));

			read = fread(curr, sizeof(t_Item), 1, f);

			t_Item2* newI= NewItem2(curr->val, curr->key,id);
			 
			id++;

			free(curr);
		}
		
	}
	else if (headerOfFile.version == 2)
	{
		
		t_Item2* curr;
		for (int i = 0; i < headerOfFile.ItemsCount; i++)
		{
			curr = (t_Item2*)malloc(sizeof(t_Item2));

			read = fread(curr, sizeof(t_Item2), 1, f);

			NewItem2(curr->val, curr->key,curr->id);
			free(curr);
		}
	}
 

	return 0;
}
