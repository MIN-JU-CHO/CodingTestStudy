#include <iostream>
#include <vector>

const int divv = 1000000;
int N;
using namespace std;
// dp[date][cumulative Late][serial Absent]
int main(void)
{
	cin >> N;
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(3, vector<int>(3, 0)));
	dp[1][0][0] = 1; dp[1][0][1] = 1; dp[1][1][0] = 1;
	for (int i = 2; i < N + 1; ++i)
	{
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % divv;
		dp[i][0][1] = dp[i - 1][0][0] % divv;
		dp[i][0][2] = dp[i - 1][0][1] % divv;
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % divv;
		dp[i][1][1] = dp[i - 1][1][0] % divv;
		dp[i][1][2] = dp[i - 1][1][1] % divv;
	}
	cout << (dp[N][0][0] + dp[N][0][1] + dp[N][0][2] + dp[N][1][0] + dp[N][1][1] + dp[N][1][2]) % divv;
}