#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];


char judge()
{
	int i = 0, j = 0;
	if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] != ' ')
		return board[i][j];
	if (board[i][j + 2] == board[i + 1][j + 1] && board[i][j + 2] == board[i + 2][j] && board[i][j] != ' ')
		return board[i][j + 2];
	for (i = 0,j = 0; j < 3; j++)
	{
		if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] != ' ')
			return board[i][j];
	}
	for (i = 0,j = 0; i < 3; i++)
	{
		if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ')
			return board[i][j];
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0;j < 3; j++)
		{
			if (board[i][j] == ' ')
				return board[i][j];
		}
	}
	return '*';
	
}


void robotPlay()
{
	int i = 0, j = 0;
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (board[i][j] == ' ')
		{
			board[i][j] = '$';
			break;
		}
	}

}

void userPlay()
{
	printf("Please enter coordinates->");
	int x = 0,y = 0;
	while(1)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x < 4 && y > 0 && y < 4)
		{
			
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = '@';
				break;
			}
			else
				printf("There are chess pieces here,please enter again!->");
		}
		else
			printf("Input error,please enter again!->");
	}
}

void initBoard()
{
	int i = 0,j = 0;
	for (i = 0;i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}

	}

}

void printBoard()
{
	printf("##########\n");
	int i = 0,j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j != 2)
			{
				printf("%c|",board[i][j]);
			}
			else
				printf("%c\n",board[i][j]);

		}
		if (i != 2)
			printf("_|_|_\n");
	}
	printf("##########\n");

//
//##########
// | | 
//_|_|_
// | | 
//_|_|_
// | |
//

//###########

}

void game()
{
	initBoard();
	srand((unsigned)time(NULL));
	char temp = ' ';
	do
	{
		printBoard();
		userPlay();
		temp = judge();
		if (temp != ' ')
			break;
		robotPlay();
		temp = judge();
	} while (temp == ' ');
	printBoard();
	switch (temp)
	{
		case '@':
			printf("User WIN!\n");
			break;
		case '$':
			printf("Bobot WIN!\n");
			break;
		case '*':
			printf("Dogfall !\n");
			break;
		dafault:
			break;
	}
}


int main()
{

	do
	{
		int i = 0;
		printf("1.Start the game\n");
		printf("2.Quit the game\n");
		printf("Please enter your options->");
		scanf("%d", &i);
		switch (i)
		{
			case 1:
				game();
				break;
			case 2:
				return 0;
			default:
				printf("Input error,please enter again!\n");
				break;
		}
	} while(1);
}
