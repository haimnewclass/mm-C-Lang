#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <windows.h>
#pragma warning(disable:4996)

int main()
{
	// To Start
	// Until Stop

	int Stop = 0;
	// kbhit() return 1 if keyboard key was clicked else returns 0
	while (!Stop)
	{
		if (kbhit())
		{
			char ch1 = getch();
			printf("Clicked %c", ch1);
			if (ch1 == 'E')
				Stop = 1;
		}
		Sleep(100);
	}

	
	while (1)
	{
		char ch = getch();
		switch (ch)
		{
			case 'S':
			{
				while (!Stop)
				{
					// Take Snapshot
					// aggrigation for all snapshot
					// Sleep (1000)
					// Until User Click Stop
					ch = getch();
				}
				printf("1");
				break;
			}
			case 'E':
			{
				printf("2");
				break;
			}

		default:
			break;
		}
	}
}