#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<bool> visited(N + 1, false);
	int result = 0;
	for (int i = 1; i <= N; ++i)
	{
		// Included Already in Count
		if (visited[i] == true)
		{
			continue;
		}
		// Visit All Connected Components
		queue<int> q;
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int next : graph[cur])
			{
				if (visited[next] == true)
				{
					continue;
				}
				q.push(next);
				visited[next] = true;
			}
		}
		++result;
	}
	cout << result;
}