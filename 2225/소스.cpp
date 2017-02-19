#include <iostream>
using namespace std;

int T[201][201] = { 0 };

int main()
{
	int N, K;

	cin >> N >> K;

	T[0][0] = 1;

	for (int i = 0; i <= N; i++) 
	{
		for (int j = 1; j <= K; j++) 
		{
			for (int x = 0; x <= i; x++) 
			{
				T[i][j] += T[i - x][j - 1];
				T[i][j] %= 1000000000;
			}
		}
	}

	cout << T[N][K] << endl;
}