#include <iostream>
#include <algorithm>
using namespace std;

int T[1001];

int main()
{
	int N, P[1001];

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> P[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j <= N; ++j)
		{
			T[j] = max(T[j - i] + P[i], T[j]);
		}
	}

	cout << T[N] << endl;
}