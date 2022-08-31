
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
struct Item {
	int id;
	int val;
	struct Item* next;
};

struct Item* head = NULL;
void freeLinkedList();

int main_3_3_1()
{
	

	int userResponse;

	printf("Click 1 for Add \n Click 2 for Print all List\n Click 3 for Exit\n");
	scanf("%d", &userResponse);
	
	struct Item* currentItem;
	struct Item* prevItem = NULL;

	while (userResponse == 1)
	{
		currentItem = malloc(sizeof(struct Item));

		if (head == NULL)
		{
			head = currentItem;
		}
		else
		{
			prevItem->next = currentItem;
		}

		scanf("%d %d", &currentItem->id, &currentItem->val);
		currentItem->next = NULL;
		
		printf("Click 1 for Add \n Click 2 for Print all List\n Click 3 for Exit\n");
		scanf("%d", &userResponse);

		prevItem = currentItem;
	}

	freeLinkedList();


}


void freeLinkedList()
{
	struct Item* currentItem = head;
	struct Item* releaseItem = head;
	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->next;
		free(releaseItem);
	}
}