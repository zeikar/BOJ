#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int T, count = 0;

	cin >> T;

	while (T--)
	{
		stack<char> stk;
		string str;

		cin >> str;

		for (int i = 0; i < str.length(); ++i)
		{
			if (stk.empty())
			{
				stk.push(str[i]);
			}
			else if (stk.top() == str[i])
			{
				stk.pop();
			}
			else
			{
				stk.push(str[i]);
			}
		}

		if (stk.empty())
		{
			++count;
		}
	}

	cout << count << endl;
}