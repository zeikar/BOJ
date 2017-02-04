#include <iostream>
using namespace std;

int board[9][9];

bool rowVisited[9][10];
bool columnVisited[9][10];
bool squareVisited[9][10];

void printBoard()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

bool checkBoard(int x, int y, int k)
{
	return rowVisited[x][k] == false && columnVisited[y][k] == false && squareVisited[3 * (x / 3) + y / 3][k] == false;
}

bool fillBoard(int remain)
{
	if (remain == 0)
	{
		printBoard();

		return true;
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] != 0)
			{
				continue;
			}

			for (int k = 1; k <= 9; ++k)
			{
				if (checkBoard(i, j, k))
				{
					board[i][j] = k;

					rowVisited[i][board[i][j]] = true;
					columnVisited[j][board[i][j]] = true;
					squareVisited[3 * (i / 3) + j / 3][board[i][j]] = true;

					if (fillBoard(remain - 1))
					{
						return true;
					}

					rowVisited[i][board[i][j]] = false;
					columnVisited[j][board[i][j]] = false;
					squareVisited[3 * (i / 3) + j / 3][board[i][j]] = false;

					board[i][j] = 0;
				}
			}

			return false;
		}
	}

	return false;
}

int main()
{
	int zeroCount = 0;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 0)
			{
				++zeroCount;
			}

			rowVisited[i][board[i][j]] = true;
			columnVisited[j][board[i][j]] = true;
			squareVisited[3 * (i / 3) + j / 3][board[i][j]] = true;
		}
	}

	fillBoard(zeroCount);
}