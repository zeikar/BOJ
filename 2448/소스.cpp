#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

char screen[3 * (1 << 10)][3 * (1 << 11)];

void printTriagle(int num, int left, int top)
{
	if(num == 3)
	{
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 5; ++j)
			{
				if(j >= 2 - i && j <= i + 2)
				{
					screen[top + i][left + j] = '*';
				}
			}
		}
		screen[top + 1][left + 2] = 0;

		return;
	}

	printTriagle(num / 2, left + num / 2, top);
	
	printTriagle(num / 2, left, top + num / 2);

	printTriagle(num / 2, left + num, top + num / 2);
}

int main()
{
	int N;
	cin >> N;

	printTriagle(N, 0, 0);

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N * 2 - 1; ++j)
		{
			if(screen[i][j] == 0)
			{
				screen[i][j] = ' ';
			}
			putchar(screen[i][j]);
		}
		putchar('\n');
	}
}