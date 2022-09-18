
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
	struct Item* curr = Tail;
	while (curr!=NULL)
	{
		printf("%d %d %d", curr->id, curr->val, curr->val2);
		curr = curr->prev;
	}
	
}
void Push(int val, int val2)
{
	struct Item* newItem = malloc(sizeof(struct Item));
	newItem->id = ID;
	ID++;
	newItem->val = val;
	newItem->val2 = val2;
	
	
	if (Head == NULL)
	{
		Tail = newItem;
		Head = newItem;
		newItem->next = NULL;
		newItem->prev = NULL;
	}
	else
	{
		newItem->next = Head;
		newItem->prev = NULL;
		Head->prev = newItem;
		Head = newItem;
	}
	
	


}

struct Item* Pop()
{
	struct Item* ret = Tail;

	if (Tail->prev != NULL)
	{
		Tail = Tail->prev;
		Tail->next = NULL;
	}

	return ret;
}


#undef SAMPLE

int main_4_1_Queue()
{
	srand(time());
	Head = NULL;
	Tail = NULL;
	ID = 0;
	struct Item* popedItem;

	char userResponse = NULL;
	while (userResponse != 'E' )
	{
		printf("Hi Dear User \n What would you like to do?\n A-to add new item  P-Print all list R-Pop next item E-to exit");
		userResponse = getch();

//#define USE_IF		
#ifdef USE_IF
		
		if (userResponse == 'A')
		{
			Push(100, 200);
		}
		else if (userResponse == 'P')
		{
			PrintList();
		}
		else if (userResponse == 'R')
		{
			Pop();
		}
		else if (userResponse == 'E')
		{
			printf("Thank you for use our Great service. See you next time. Drink only water\n");
		}
		else
		{
			printf("Wrong selection. Try be more sharp\n");
		}
#else

		switch (userResponse)
		{
			case 'A':
				
				Push(rand(), rand());
				break;
			case 'P': PrintList();
				break;
			case 'R': 
				
				popedItem = Pop();

				printf("Item %d %d %d", popedItem->id, popedItem->val, popedItem->val2);
				free(popedItem);
				break;
			case 'E': printf("Thank you for use our Great service. See you next time. Drink only water\n");
				break;

			default:
				printf("Wrong selection. Try be more sharp\n");
				break;
		}
	}
#endif
#ifdef SAMPLE

	Push(12, 1);
	Push(120, 2);
	struct Item* item  = Pop();
	printf("%d", item->val);
	free(item);

	Push(12, 3);
	item = Pop();
	free(item);

#endif  

 
}