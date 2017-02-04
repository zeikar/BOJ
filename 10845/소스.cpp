#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int N;
	queue<int> que;

	cin >> N; 

	while(N--)
	{
		string command;
		int num;

		cin >> command;

		if(command == "push")
		{
			cin >> num;
			que.push(num);
		}
		else if(command == "pop")
		{
			if(!que.empty())
			{
				cout << que.front() << endl;
				que.pop();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if(command == "size")
		{
			cout << que.size() << endl;
		}
		else if(command == "empty")
		{
			cout << (que.empty() ? 1 : 0) << endl;
		}
		else if(command == "front")
		{
			if(!que.empty())
			{
				cout << que.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else
		{
			if(!que.empty())
			{
				cout << que.back() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
}