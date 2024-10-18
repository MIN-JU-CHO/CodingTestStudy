#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> inputs(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> inputs[i];
	}
	sort(inputs.begin(), inputs.end());

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		int val = inputs[i];
		int start = 0, end = N - 1, sum = 0;
		while (start < end)
		{
			// skip itself
			if (start == i)
			{
				++start;
				continue;
			}
			else if (end == i)
			{
				--end;
				continue;
			}
			sum = inputs[start] + inputs[end];
			if (sum == val)
			{
				++result;
				break;
			}
			else if (sum < val)
			{
				++start;
			}
			else
			{
				--end;
			}
		}
	}

	cout << result;
}