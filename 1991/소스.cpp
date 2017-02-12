#include <iostream>
using namespace std;

const int LEFT = 1;
const int RIGHT = 2;

int graph[26][26];

int findChild(int node, int pos)
{
	for(int i = 0; i < 26; ++i)
	{
		if(graph[node][i] == pos)
		{
			return i;
		}
	}
	return -1;
}

void preorder(int node)
{
	int left = findChild(node, LEFT);
	int right = findChild(node, RIGHT);

	cout << (char)(node + 'A');

	if(left != -1)
	{
		preorder(left);
	}

	if(right != -1)
	{
		preorder(right);
	}
}

void inorder(int node)
{
	int left = findChild(node, LEFT);
	int right = findChild(node, RIGHT);

	if(left != -1)
	{
		inorder(left);
	}

	cout << (char)(node + 'A');

	if(right != -1)
	{
		inorder(right);
	}
}

void postorder(int node)
{
	int left = findChild(node, LEFT);
	int right = findChild(node, RIGHT);

	if(left != -1)
	{
		postorder(left);
	}

	if(right != -1)
	{
		postorder(right);
	}

	cout << (char)(node + 'A');
}



int main()
{
	int N;
	int rootNode = 0;

	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		char n, l, r;

		cin >> n >> l >> r;

		if(l != '.')
		{
			graph[n - 'A'][l - 'A'] = LEFT;
		}

		if(r != '.')
		{
			graph[n - 'A'][r - 'A'] = RIGHT;
		}
	}

	preorder(rootNode);

	cout << endl;

	inorder(rootNode);

	cout << endl;

	postorder(rootNode);

	cout << endl;
}