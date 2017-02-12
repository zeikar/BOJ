#include <iostream>
using namespace std;

const int H = 0;
const int E = 1;
const int L = 2;
const int O = 3;
const int W = 4;
const int R = 5;
const int D = 6;

bool notSameNum(int* num)
{
	bool isVisited[10] = { false };

	for (int i = 0; i < 7; ++i)
	{
		if (isVisited[num[i]])
		{
			return false;
		}

		isVisited[num[i]] = true;
	}

	return true;
}

int calHelloWorld(int* num)
{
	int result = num[H] * 10000 + num[E] * 1000 + num[L] * 110 + num[O];

	result += num[W] * 10000 + num[O] * 1000 + num[R] * 100 + num[L] * 10 + num[D];

	return result;
}

void printHelloWorld(int* num)
{
	cout << "  " << num[H] << num[E] << num[L] << num[L] << num[O] << endl;
	cout << "+ " << num[W] << num[O] << num[R] << num[L] << num[D] << endl;
	cout << "-------" << endl;
	
	if (calHelloWorld(num) >= 100000)
	{
		cout << ' ' << calHelloWorld(num) << endl;
	}
	else
	{
		cout << "  " << calHelloWorld(num) << endl;
	}
}

bool findHelloWorld(int* num, int idx, int answer)
{
	if (idx == 7)
	{
		if(calHelloWorld(num) == answer && notSameNum(num))
		{
			printHelloWorld(num);
			return true;
		}
		return false;
	}

	if (idx != H && idx != W)
	{
		num[idx] = 0;
		if (findHelloWorld(num, idx + 1, answer))
		{
			return true;
		}
	}

	for (int i = 1; i <= 9; ++i)
	{
		num[idx] = i;

		if (findHelloWorld(num, idx + 1, answer))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int num[7] = { 0 }, answer;

	cin >> answer;

	if (findHelloWorld(num, 0, answer) == false)
	{
		cout << "No Answer" << endl;
	}
}