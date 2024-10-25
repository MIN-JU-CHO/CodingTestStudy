#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>

#define X first
#define Y second

using namespace std;
int main(void)
{
	int n;
	scanf_s("%d", &n);
	vector<pair<float, float>> stars(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		scanf_s("%f %f", &stars[i].X, &stars[i].Y);
	}
	// save info of edges (bidirectional)
	vector<vector<float>> edges(n + 1, vector<float>(n + 1, -1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			// memoization
			if (edges[j][i] != -1)
			{
				edges[i][j] = edges[j][i];
				//printf("dist [%d] [%d] = %f\n", i, j, edges[i][j]);
				continue;
			}
			edges[i][j] = sqrt(pow(stars[i].X - stars[j].X, 2) + pow(stars[i].Y - stars[j].Y, 2));
			//printf("dist [%d] [%d] = %f\n", i, j, edges[i][j]);
		}
	}

	bool visited[101];
	fill(visited, visited + 101, false);

	// first search with random star
	visited[1] = true;
	priority_queue<tuple<float, int, int>, vector<tuple<float, int, int>>, greater<tuple<float, int, int>>> q;
	for (int i = 2; i <= n; ++i)
	{
		q.push({ edges[1][i], 1, i });
	}

	// prim algorithm
	double result = 0;
	while (!q.empty())
	{
		double dist;
		int start, end;
		tie(dist, start, end) = q.top(); q.pop();
		if (visited[end] == true)
		{
			continue;
		}
		//printf("dist btw %d %d : %f\n", start, end, dist);
		visited[end] = true;
		result += dist;
		for (int i = 1; i <= n; ++i)
		{
			if (i == end || visited[i] == true || edges[end][i] < 0)
			{
				continue;
			}
			q.push({ edges[end][i], end, i });
		}
	}

	printf("%.2f", result);
}