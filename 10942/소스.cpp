#include <iostream>
#include <cstdio>
using namespace std;

char T[2001][2001] = {0};

void findPalindrome(int* arr, int N, int left, int right)
{
	if(right == left)
	{
		T[left][right] = 1;
		return;
	}

	if(T[left + 1][right - 1] == -1)
	{
		T[left][right] = -1;
		return;
	}
	else if(T[left + 1][right - 1] == 1)
	{
		if(arr[left] == arr[right])
		{
			T[left][right] = 1;
		}
		else
		{
			T[left][right] = -1;
		}
		return;
	}

	for(int i = 0; i <= (right - left) / 2; ++i)
	{
		if(arr[left + i] != arr[right - i])
		{
			T[left][right] = -1;
			return;
		}
	}

	T[left][right] = 1;
}

int main()
{
	int N, M;
	int arr[2000];

	scanf("%d", &N);

	for(int i = 0; i < N; ++i)
	{
		scanf("%d", arr + i);
	}

	scanf("%d", &M);
	
	while(M--)
	{
		int s, e;

		scanf("%d %d", &s, &e);

		findPalindrome(arr, N, min(s - 1, e - 1), max(s - 1, e - 1));

		if(T[min(s - 1, e - 1)][max(s - 1, e - 1)] == -1)
		{
			putchar('0');
			putchar('\n');
		}
		else
		{
			putchar('1');
			putchar('\n');
		}
	}
}