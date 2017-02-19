#include <iostream>
#include <string>
using namespace std;

int T[5000];

int main()
{
	string password;

	cin >> password;

	T[0] = 1;

	for (int i = 1; i <= password.length(); ++i)
	{
		if (password[i - 1] >= '1' && password[i - 1] <= '9')
		{
			T[i] += T[i - 1];
			T[i] %= 1000000;
		}

		if (i >= 2 && (password[i - 2] == '1' || (password[i - 2] == '2' && password[i - 1] <= '6')))
		{
			T[i] += T[i - 2];
			T[i] %= 1000000;
		}
	}

	cout << T[password.length()] << endl;
}