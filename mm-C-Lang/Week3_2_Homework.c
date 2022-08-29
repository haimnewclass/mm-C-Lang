
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


void Targil3();
void Targil5();
void Targil6();

struct sample
{
	int val;
	char name[100];
	short answer;
};


int main_3_2_2()
{
	Targil6();

	return 0;
}


void Targil6()
{
	int count = 0;

	printf("\nEnter Count of sctructures:");
	scanf("%d", &count);

	struct sample* buffer =(struct sample*) malloc(sizeof(struct sample) * count);

	if (!buffer)
	{
		// error
		return;
	}

	struct sample* currentItem = buffer;

	for (int i = 0; i < count; i++)
	{
		int val;
		char name[100];
		short answer;

		printf("\nEnter Val:");
		scanf("%d", &val);

		printf("\nEnter Name:");
		scanf("%s", name);
		
		answer = (strlen(name) > 5 && val > 10) ? 1 : 0;
		currentItem->val = val;
		currentItem->answer = answer;
		strcpy(currentItem->name, name);
		currentItem++;

	}
	
	FILE* f = fopen("samples.data", "w");
	fwrite(buffer, sizeof(struct sample), count, f);
	fclose(f);
	free(buffer);
}
void Targil5()
{
	FILE* f =  fopen("exe5_4.bin", "r");
	int  buffer;
	if (f)
	{
		int read = 0;
		int count = 0;
		int sum = 0;
		while ((read = fread(&buffer, sizeof(int), 1,f)) > 0)
		{
			count++;
			sum += buffer;
		}
		
		fclose(f);
	}

	

}
void Targil3()
{
	 
	struct sample arr[3];
	for (int i = 0; i < 3; i++)
	{
		int val;
		char name[100];
		short answer;

		printf("\nEnter Val:");
		scanf("%d", &val);

		printf("\nEnter Name:");
		scanf("%s", name);

		arr[i].val = val;
		strcpy(arr[i].name ,name);
		answer = (strlen(name) > 5 && val > 10) ? 1 : 0;
		
		arr[i].answer =  answer;
		
	}

	FILE* f = fopen("3samples.dat", "w");
	fwrite(arr, sizeof(struct sample), 3, f);
	fclose(f);
}
