#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	set<int> pin;
	for (int i = 0; i < M; ++i)
	{
		int temp;
		cin >> temp;
		pin.insert(temp);
	}
	vector<int> dp(N + 1);
	dp[1] = 1;
	if (pin.find(1) == pin.end())
	{
		dp[2] = 2;
	}
	else
	{
		dp[2] = 1;
	}
	for (int i = 3; i <= N; ++i)
	{
		// If Current seat is Vip
		if (pin.find(i) != pin.end())
		{
			dp[i] = dp[i - 1];
		}
		else
		{
			// If Prev seat is Vip
			if (pin.find(i - 1) != pin.end())
			{
				dp[i] = dp[i - 2];
			}
			// If PrevPrev seat is Vip
			else if (pin.find(i - 2) != pin.end())
			{
				dp[i] = dp[i - 1] * 2;
			}
			else
			{
				dp[i] = dp[i - 2] + dp[i - 1];
			}
		}
	}
	cout << dp[N];
}