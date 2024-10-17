#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, budget, start, mid, end, result;
	cin >> N;
	vector<int> demands(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> demands[i];
	}
	cin >> budget;
	start = 0;
	end = *(max_element(demands.begin(), demands.end()));
	result = start;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			sum += min(demands[i], mid);
		}
		if (sum <= budget)
		{
			result = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << result;
}