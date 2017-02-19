#include <iostream>
using namespace std;

int T[101][10] = { 0 };
const int mod = 1000000000;

int main()
{
	int N, result = 0;

	cin >> N;

	for (int i = 1; i <= 9; i++) 
	{
		T[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) 
	{
		for (int j = 0; j <= 9; j++) 
		{
			if (j - 1 >= 0)
			{
				T[i][j] += T[i - 1][j - 1];
			}
			if (j + 1 <= 9) 
			{
				T[i][j] += T[i - 1][j + 1];
			}

			T[i][j] %= mod;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		result += T[N][i];
		result %= mod;
	}

	cout << result << endl;
}