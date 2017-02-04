#include <iostream>
#include <queue>
using namespace std;

int dfsVisited[1001];
int bfsVisited[1001];
int graph[1001][1001];


void dfs(int V, int N)
{
	cout << V << ' ';

	dfsVisited[V] = 1;

	for (int i = 1; i <= N; ++i)
	{
		if (!dfsVisited[i] && graph[V][i])
		{
			dfs(i, N);
		}
	}
}

void bfs(int V, int N)
{
	queue<int> que;
	
	que.push(V);
	bfsVisited[V] = 1;

	while (!que.empty())
	{
		V = que.front();
		que.pop();

		cout << V << ' ';

		for (int i = 1; i <= N; ++i)
		{
			if (!bfsVisited[i] && graph[V][i])
			{
				que.push(i);
				bfsVisited[i] = 1;
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	/// init
	for (int i = 0; i < M; ++i)
	{
		int x, y;
		cin >> x >> y;

		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	
	dfs(V, N);

	cout << endl;

	bfs(V, N);
}