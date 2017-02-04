#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N;
	stack<int> stk;

	cin >> N;

	while (N--)
	{
		string command;

		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;
			stk.push(num);
		}
		else if (command == "pop")
		{
			if (stk.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << stk.top() << endl;
				stk.pop();
			}
		}
		else if (command == "size")
		{
			cout << stk.size() << endl;
		}
		else if (command == "empty")
		{
			cout << (stk.empty() ? 1 : 0) << endl;
		}
		else
		{
			if (stk.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << stk.top() << endl;
			}
		}
	}
}