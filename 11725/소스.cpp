#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

vector<int> edges[100001];
bool isVisited[100001];
int parent[100001];

int main()
{
	int N;

	cin >> N;

	for (int i = 1; i < N; ++i)
	{
		int a, b;
		//cin >> a >> b;
		scanf("%d %d", &a, &b);

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	queue<int> que;
	que.push(1);
	isVisited[1] = true;

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		for (int i = 0; i < edges[current].size(); ++i)
		{
			int dest = edges[current][i];

			if (isVisited[dest])
			{
				continue;
			}

			isVisited[dest] = true;
			parent[dest] = current;
			que.push(dest);
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		//cout << parent[i] << endl;
		printf("%d\n", parent[i]);
	}
}