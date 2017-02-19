#include <iostream>
#include <algorithm>
using namespace std;

int trees[1000000];

long long sumofTrees(int height, int N)
{	
	long long sum = 0;

	for(int i = 0; i < N; ++i)
	{
		sum += max(0, trees[i] - height);
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);

	int N, M, result = 0;
	int low = 0, high = 0;

	cin >> N >> M;

	for(int i = 0; i < N; ++i)
	{
		cin >> trees[i];

		high = max(high, trees[i]);
	}

	while (low <= high)
	{
		int mid = (long long)(low + high) / 2;

		if(sumofTrees(mid, N) < M)
		{
			high = mid - 1;
		}
		else
		{
			result = max(result, mid);
			low = mid + 1;
		}
	}

	cout << result << endl;
}