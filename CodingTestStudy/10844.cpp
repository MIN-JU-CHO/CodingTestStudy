#include<iostream>

using namespace std;


int main(void)
{
	int N;
	cin >> N;
	
	int dp[100][10] = { 0, };

	// ���� 1 ��� ��
	for (int i = 1; i <= 9; ++i)
	{
		dp[0][i] = 1;
	}

	// Bottom up
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			// 0 �տ��� 1�ۿ� ����
			if (j == 0)
			{
				dp[i][0] = dp[i - 1][1];
			}
			// 9 �տ��� 8�ۿ� ����
			else if (j == 9)
			{
				dp[i][9] = dp[i - 1][8];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= 1000000000;
		}
	}

	int result = 0;
	for (int i = 0; i <= 9; ++i)
	{
		result = (result + dp[N - 1][i]) % 1000000000;
	}
	cout << result << endl;
}