
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
	

int main_2_3_7()
{
	

	struct Item
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};
	struct Item kuku;


	struct Item item2;

	kuku.price = 12;
	strcpy(kuku.name, "Cola");
	strcpy(kuku.color, "Black");
	kuku.price = 34;

	item2.price = 9;
	strcpy(item2.name, "Pepsi");
	strcpy(item2.color, "Black");
	//printf("Item:%s Price:%d", kuku.name, kuku.price);




	struct Item itemList[10];
	
 
	for (int i = 0; i < 3; i++)
	{

		scanf("%d %s %s %d", &itemList[i].barcode, itemList[i].name, itemList[i].color, &itemList[i].price);
		 

		//itemList[i].color = 
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s %s %d\n", itemList[i].name, itemList[i].color, itemList[i].price);
		//itemList[i].color = 
	}
	

}