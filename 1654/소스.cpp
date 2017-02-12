#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long long K, N, sum = 0, lan[10000], len;

	cin >> K >> N;   

	for(int i = 0; i < K; ++i)
	{
		scanf("%lld", lan + i);
		sum += lan[i];
	}

	long long low = 0, high = sum / N + 1;

	while(low < high)
	{
		int count = 0;
		len = (low + high) / 2;

		for(int i = 0; i < K; ++i)
		{
			count += lan[i] / len;
		}

		if(count >= N)
		{
			if(low == len)
			{
				break;
			}
			low = len;
		}
		else
		{
			high = len;
		}
	} 

	cout << len << endl;
}