#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int level[200001];
int parent[200001];

void printPath(int N, int current)
{
	if (current == N)
	{
		printf("%d ", current);
		return;
	}

	printPath(N, parent[current]);

	printf("%d ", current);
}

int main()
{
	int N, K;

	cin >> N >> K;

	queue<int> que;
	que.push(N);
	level[N] = 1;

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		int dir[3] = { -1, 1, current };

		for (int d = 0; d < 3; ++d)
		{
			int dest = current + dir[d];

			if (dest < 0 || dest >= 200000 || level[dest] != 0)
			{
				continue;
			}

			que.push(dest);
			level[dest] = level[current] + 1;
			parent[dest] = current;
		}
	}

	cout << level[K] - 1 << endl;

	printPath(N, K);
}