
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	struct Item {
		int id;
		int val;
		struct Item* next;
	};

	int userResponse;

	printf("Click 1 for Add \n Click 2 for Print all List\n Click 3 for Exit\n");
	scanf("%d", &userResponse);
	struct Item* head = NULL;
	struct Item* currentItem;
	struct Item* prevItem;

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
		prevItem = currentItem;


		printf("Click 1 for Add \n Click 2 for Print all List\n Click 3 for Exit\n");
		scanf("%d", &userResponse);

	}



}
