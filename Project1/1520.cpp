#include<stdio.h>
#include<vector>

using namespace std;
int m, n;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
vector<vector<int>> graph, dp;
int dfs(int x, int y)
{
	if (x == m - 1 && y == n - 1)
	{
		if (dp[m - 1][n - 1] == -1)
		{
			dp[m - 1][n - 1] = 1;
		}
		return 1;
	}
	// Memoization
	// �߰� ��� �̹� �湮 ���� ���, ����� ��� �� ��ȯ�Ͽ� ���� ������ Ž������ �ʾƵ� ��
	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}
	dp[x][y] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx < 0 || cx >= m || cy < 0 || cy >= n)
		{
			continue;
		}
		if (graph[cx][cy] >= graph[x][y])
		{
			continue;
		}
		dp[x][y] += dfs(cx, cy);
	}
	return dp[x][y];
}
int main(void)
{
	scanf("%d %d", &m, &n);
	graph.assign(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	dp.assign(m, vector<int>(n, -1));
	printf("%d", dfs(0, 0));
}