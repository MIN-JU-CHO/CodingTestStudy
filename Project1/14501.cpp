#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main(void)
{
	int N;
	cin >> N;
	vector<int> T(N+2, 0), P(N+2, 0), dp(N+2, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> T[i] >> P[i];
	}

	// memozation
	for (int i = 1; i <= N; ++i)
	{
		// Bring prev profit or maintain current profit
		dp[i] = max(dp[i], dp[i - 1]);

		// can work done before Retire
		if (i + T[i] - 1 <= N)
		{
			// Update future profit
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		}
	}

	cout << max(dp[N], dp[N+1]);
}