#include <iostream>
#include <cstdio>
using namespace std;

void printSubset(int* arr, int* printNums, int N, int start, int count)
{
	if (count == 6)
	{
		for (int i = 0; i < count; ++i)
		{
			printf("%d ", printNums[i]);
		}
		putchar('\n');
		return;
	}

	for (int i = start; i < N; ++i)
	{
		printNums[count] = arr[i];
		printSubset(arr, printNums, N, i + 1, count + 1);
	}
}

int main()
{
	bool firstInput = true;
	while (1)
	{
		int N;
		int arr[13], printNums[6];
		scanf("%d", &N);

		if (N == 0)
		{
			break;
		}

		if (!firstInput)
		{
			putchar('\n');
		}

		for (int i = 0; i < N; ++i)
		{
			scanf("%d", arr + i);
		}

		printSubset(arr, printNums, N, 0, 0);

		firstInput = false;
	}
}