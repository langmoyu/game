#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int board[11][11];
int boardu[11][11];

int sweeping(int x,int y)
{
	int i = 0, j = 0;
	if (board[x][y] == -1)
	{
		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
			{
				if (board[i][j] == -1)
					boardu[i][j] = -1;
			}
		}
		return -1;
	}
	else
	{
		for (i = x - 1; i < x + 2; i++)
		{
			for (j = y - 1; j < y + 2; j++)
			{
				if (board[i][j] != -1)  
				boardu[i][j] = board[i][j];
			}
		}
		return 0;
	}
}


void  initBoard()
{
	int i = 0, j = 0;
	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 11; j++)
		{
			board[i][j] = 0;
			boardu[i][j] = -2;
		}
	}
	int temp  = 0;
       	while (1)
	{
		int x =	rand() % 8 + 1;
		int y = rand() % 8 + 1;
		if (board[x][y] == 0)
		{
			board[x][y] = -1;
			temp++;
		}
		if (temp == 10)
			break;
	
	}
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (board[i][j] == -1)
				continue;
			int x = 0, y = 0,value = 0;
			for (x = 0; x < 3 ; x++)
			{
				for (y = 0; y < 3; y++)
				{
					if (board[i - 1 + x][j - 1 + y] == -1)
						value++;
				}
			}
			board[i][j] = value;
		}
	}
		
}


void printBoard()
{
	int i = 0, j = 0;
	printf("# 1 2 3 4 5 6 7 8 9 #\n");
	for (i = 1; i < 10; i++)
	{
		printf("%d", i);
		for (j = 1; j < 10; j++)
		{
			if (boardu[i][j] == -2)
				printf(" %c", '*');
			else if (boardu[i][j] == -1)
				printf(" %c", '$');
			else if (boardu[i][j] == 0)
				printf(" %c", ' ');
			else
				printf(" %d", boardu[i][j]);
		}
		printf(" #\n");
	}
	printf("# # # # # # # # # # #\n");
}


void game()
{
	srand((unsigned)time(NULL));
	initBoard();
	do
	{
		printBoard();		
		int temp = 0;
		while (1)
		{
			int x = 0, y = 0;
			printf("Please enter coordinate->");
			scanf("%d %d", &x, &y);
			if (x > 0 && x < 10 && y > 0 && y < 10)
			{
				temp = sweeping(x, y);
				break;
			}
		
			else
				printf("Input error!Please enter again!->");
		}
		if (temp == -1)
		{
			printBoard();
			printf("You DIE!!\n");
			break;
		}

		
	} while (1);
	
}

int main()
{
	do
	{
		int i = 0;
		printf("1.Start the game!\n");
		printf("2.Quit the game!\n");
		printf("Please enter your choose->\n");
		scanf("%d", &i);
		switch (i)
		{
			case 1:
				game();
				break;
			case 2:
				return 0;
				break;
			default:
				printf("Input error!Please enter again!->\n");
				break;
		}
	} while(1);
}
