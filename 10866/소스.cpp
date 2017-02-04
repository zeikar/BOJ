#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <deque>
using namespace std;

int main()
{
	deque<int> deq;
	stringstream result;
	int N;
	cin >> N;

	while (N--)
	{
		string command;
		cin >> command;

		// push front
		if (command[1] == 'u' && command[5] == 'f')
		{
			int num;
			scanf("%d", &num);

			deq.push_front(num);
		}
		// push back
		else if (command[1] == 'u' && command[5] == 'b')
		{
			int num;
			scanf("%d", &num);

			deq.push_back(num);
		}
		// pop front
		else if (command[1] == 'o' && command[4] == 'f')
		{
			if (deq.empty())
			{
				result << -1 << '\n';
			}
			else
			{
				result << deq.front() << '\n';
				deq.pop_front();
			}
		}
		// pop back
		else if (command[1] == 'o' && command[4] == 'b')
		{
			if (deq.empty())
			{
				result << -1 << '\n';
			}
			else
			{
				result << deq.back() << '\n';
				deq.pop_back();
			}
		}
		// size
		else if (command[0] == 's')
		{
			result << deq.size() << '\n';
		}
		// empty
		else if (command[0] == 'e')
		{
			result << (int)deq.empty() << '\n';
		}
		// front
		else if (command[0] == 'f')
		{
			if (deq.empty())
			{
				result << -1 << '\n';
			}
			else
			{
				result << deq.front() << '\n';
			}
		}
		// back
		else
		{
			if (deq.empty())
			{
				result << -1 << '\n';
			}
			else
			{
				result << deq.back() << '\n';
			}
		}
	}

	cout << result.str();
}