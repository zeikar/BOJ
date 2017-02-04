#include <iostream>
#include <string>
using namespace std;

struct Stack
{
	char stack[50];
	int top;
};

Stack stk;

void push(char ch)
{
	stk.stack[stk.top++] = ch;
}

void pop()
{
	--stk.top;
}

int empty()
{
	return stk.top == 0;
}

void init()
{
	stk.top = 0;
}

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		char str[51], *result = "YES";

		cin >> str;

		init();

		for (int i = 0; str[i]; ++i)
		{
			if (str[i] == '(')
			{
				push(str[i]);
			}
			else
			{
				if (empty())
				{
					result = "NO";
					break;
				}

				pop();
			}
		}

		if (!empty())
		{
			result = "NO";
		}

		cout << result << endl;
	}
}