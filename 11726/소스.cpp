#include <iostream>
using namespace std;

int T[1001];

int tiling(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	if(T[n] != 0)
	{
		return T[n];
	}

	return T[n] = (tiling(n - 1) + tiling(n - 2)) % 10007;
}

int main()
{
	int n;
	cin >> n;
	cout << tiling(n) << endl;
}