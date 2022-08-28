
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_2_3_8()
{


	struct Item
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};


	struct Item kuku;
	struct Item kuku2;

	kuku.barcode = 111;
	kuku.price = 12;
	strcpy(kuku.name, "Cola");
	strcpy(kuku.color, "Black");
	kuku.price = 34;

	kuku2.barcode = 222;
	kuku2.price = 12;
	strcpy(kuku2.name, "Pepsi");
	strcpy(kuku2.color, "Green");
	kuku2.price = 22;

	FILE* f = fopen("ItemList.dat","w");
	if (f != NULL)
	{
		fwrite(&kuku, sizeof(struct Item), 1, f);
		fwrite(&kuku2, sizeof(struct Item), 1, f);

		fclose(f);

		struct Item ItemToRead;
		f = fopen("ItemList.dat", "r");
		if (f != NULL)
		{
			//how many structures read
			int alreadyRead = fread(&ItemToRead, sizeof(struct Item), 1, f);
			while (alreadyRead != 0)
			{

				alreadyRead = fread(&ItemToRead, sizeof(struct Item), 1, f);
			}

			fclose(f);
		}


	}


	

}