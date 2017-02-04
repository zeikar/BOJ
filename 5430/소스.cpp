#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string p, arr;
		stringstream result;
		deque<int> nums;
		int n;

		cin >> p >> n >> arr;

		int tempNum = 0;
		for (int i = 1; i < arr.length(); ++i)
		{
			if (arr[i] == ',' || arr[i] == ']')
			{
				if (tempNum != 0)
				{
					nums.push_back(tempNum);
					tempNum = 0;
				}
			}
			else
			{
				tempNum *= 10;
				tempNum += arr[i] - '0';
			}
		}

		int rCount = 0;
		for (int i = 0; i < p.length(); ++i)
		{
			if (p[i] == 'R')
			{
				++rCount;
			}
			else
			{
				if (nums.size() == 0)
				{
					result << "error";
					break;
				}

				if (rCount % 2 == 0)
				{
					nums.pop_front();
				}
				else
				{
					nums.pop_back();
				}
			}
		}

		bool first = true;
		if (result.str() != "error")
		{
			result << '[';

			if (rCount % 2 == 0)
			{
				for (int i = 0; i < nums.size(); ++i)
				{
					if (first)
					{
						result << nums[i];
						first = false;
					}
					else
					{
						result << ',';
						result << nums[i];
					}
				}
			}
			else
			{
				for (int i = nums.size() - 1; i >= 0; --i)
				{
					if (first)
					{
						result << nums[i];
						first = false;
					}
					else
					{
						result << ',';
						result << nums[i];
					}
				}
			}

			result << ']';
		}

		cout << result.str() << endl;
	}
}