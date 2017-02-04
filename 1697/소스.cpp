#include <iostream>
#include <queue>
using namespace std;

struct Point
{
	int x;
	int level;
};

bool isVisited[100001];

int main()
{
	int N, K, result;
	queue<Point> que;

	cin >> N >> K;

	Point temp = { N, 0 };

	que.push(temp);

	while (!que.empty())
	{
		Point current = que.front();
		que.pop();

		if (current.x == K)
		{
			result = current.level;
			break;
		}

		if (current.x < 0 || current.x > 100000 || isVisited[current.x])
		{
			continue;
		}

		isVisited[current.x] = true;

		temp.level = current.level + 1;
		temp.x = current.x - 1;
		que.push(temp);

		temp.x = current.x + 1;
		que.push(temp);

		temp.x = 2 * current.x;
		que.push(temp);
	}

	cout << result << endl;
}