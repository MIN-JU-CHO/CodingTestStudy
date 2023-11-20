#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
	int N;
	scanf("%d", &N);
	long long x, y;
	long long dpX, dpY;
	vector<pair<long long, long long>> input;
	while (N--)
	{
		scanf("%lld", &x); scanf("%lld", &y);
		input.push_back({ x, y });
	}
	sort(input.begin(), input.end());

	dpX = input[0].first; dpY = input[0].second;

	long long result = 0;
	for (pair<long long, long long> coord : input)
	{
		x = coord.first;
		y = coord.second;
		// new range update 
		if (dpY < x)
		{
			result += dpY - dpX;
			dpX = x; dpY = y;
		}
		// update range size
		else if (dpY < y)
		{
			dpY = y;
		}
	}
	result += dpY - dpX;
	printf("%lld", result);
}