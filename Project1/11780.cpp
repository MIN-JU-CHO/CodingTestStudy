#include<vector>
#include<stdio.h>

using namespace std;
const int INF = 0x3f3f3f3f;
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF)), pre(n + 1, vector<int>(n + 1, -1));
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c < adj[a][b])
		{
			adj[a][b] = c;
			pre[a][b] = b;
		}
	}
	// floyd
	for (int k = 1; k <= n; ++k)
	{
		for (int s = 1; s <= n; ++s)
		{
			if (s == k)
			{
				continue;
			}
			for (int t = 1; t <= n; ++t)
			{
				if (t == s || t == k)
				{
					continue;
				}
				if (adj[s][k] + adj[k][t] < adj[s][t])
				{
					adj[s][t] = adj[s][k] + adj[k][t];
					pre[s][t] = pre[s][k];
				}
			}
		}
	}
	// print min distance
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (adj[i][j] == INF)
			{
				printf("0 ");
				continue;
			}
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
	// print recovery path
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (adj[i][j] == INF)
			{
				printf("0\n");
				continue;
			}
			vector<int> route;
			int node;
			route.push_back(i);
			for (node = pre[i][j]; node != j; node = pre[node][j])
			{
				route.push_back(node);
			}
			route.push_back(node);
			printf("%d ", (int)route.size());
			for (int v : route)
			{
				printf("%d ", v);
			}
			printf("\n");
		}
	}
}