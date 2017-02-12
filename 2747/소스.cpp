#include <iostream>
using namespace std;

int T[21];

int fibonacci(int n)
{
	if(n <= 1)
	{
		return n;
	}

	if(T[n] != 0)
	{
		return T[n];
	}

	return T[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
}