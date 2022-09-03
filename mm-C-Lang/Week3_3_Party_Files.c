
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main_3_3_10()
{
	// Write chars into file
	FILE* kuku = fopen("file.txt", "w");
	if (kuku == NULL)
	{
		// error
		return;
	}
	fputc('S', kuku);
	fputc('H', kuku);
	fputc('A', kuku);
	fputc('L', kuku);
	fputc('O', kuku);
	fputc('M', kuku);

	fclose(kuku);

	// write chars into file
	kuku = fopen("file.txt", "r");
	char c;
	int count = 0;
	c = fgetc(kuku);

	while (c!=EOF)
	{
		c= fgetc(kuku);
		 
		count++;
	}
	 

	fclose(kuku);


	/////////////////////////////////////////////////////////////////
	////
	/////////////////////////////////////////////////////////////////

	kuku = fopen("file123.txt", "w");

	int a = 100;
	int b = 200;
	int d = 300;

	fwrite(&a, sizeof(int), 1, kuku);
	fwrite(&b, sizeof(int), 1, kuku);
	fwrite(&d, sizeof(int), 1, kuku);

	fclose(kuku);

	kuku = fopen("file123.txt", "r");
	int* place = malloc(sizeof(int)*3);
	
	int howManyBlocksWereRead =  fread(place,sizeof(int), 3, kuku);


	fclose(kuku);
	free(place);

	


	/// <summary>
	/// struct
	/// </summary>
	/// <returns></returns>
	
	struct BasketBallGame
	{
		int Team1;
		int Team2;
		int TimeDuration;
	};
	
	struct BasketBallGame game1;
	struct BasketBallGame game2;
	struct BasketBallGame game3 =  {90,89,40};

	game1.Team1 = 100;
	game1.Team2 = 98;
	game1.TimeDuration = 40;

	game2.Team1 = 67;
	game2.Team2 = 88;
	game2.TimeDuration = 50;

	kuku = fopen("basketBall.bin", "w");
	fwrite(&game1, sizeof(struct BasketBallGame), 1, kuku);
	fwrite(&game2, sizeof(struct BasketBallGame), 1, kuku);
	fwrite(&game3, sizeof(struct BasketBallGame), 1, kuku);
	fclose(kuku);

	struct BasketBallGame arr[3];
	arr[0] = game1;
	arr[1] = game2;
	arr[2] = game3;
	 

	kuku = fopen("basketBall.bin", "w");
	 
	fwrite(arr, sizeof(struct BasketBallGame), 3, kuku);
	fclose(kuku);

	/// <summary>
	/// Dynamic memory
	/// </summary>
	/// <returns></returns>

	struct BasketBallGame* placer = (struct BasketBallGame*)malloc(sizeof(struct BasketBallGame) * 100);
	struct BasketBallGame* root = placer;
	placer->Team1 = 67;
	placer->Team2 = 66;
	placer++;
	placer->Team1 = 99;
	placer->Team2 = 45;
	placer++;
	placer->Team1 = 45;
	placer->Team2 = 47;

	
	kuku = fopen("basketBall3.bin", "w");

	fwrite(root, sizeof(struct BasketBallGame), 10, kuku);
	fclose(kuku);
	free(root);


	return 0;

}