#include <vector>
#include <queue>
#include <stdio.h>

#define weight first
#define vertex second
using namespace std;

int V, E, st, en;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[1001];
int d[1001], pre[1001];

int main(void)
{
	scanf("%d", &V);
	scanf("%d", &E);
	while (E--)
	{
		int u, v, w;
		scanf("%d", &u);
		scanf("%d", &v);
		scanf("%d", &w);
		adj[u].push_back({ w, v });
	}
	scanf("%d", &st);
	scanf("%d", &en);

	// 첫 노드 0, 나머지 INF
	fill(d, d + V + 1, INF);
	d[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, st });
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		// 이미 최단거리 존재 시 skip
		if (cur.weight != d[cur.vertex])
		{
			continue;
		}
		for (pair<int, int> next : adj[cur.vertex])
		{
			// 이미 최단거리 일 때
			if (d[next.vertex] <= d[cur.vertex] + next.weight)
			{
				continue;
			}
			d[next.vertex] = d[cur.vertex] + next.weight;
			pq.push({ d[next.vertex], next.vertex });
			pre[next.vertex] = cur.vertex;
		}
	}

	vector<int> route;
	int curNode = en;
	while (curNode != st)
	{
		route.push_back(curNode);
		curNode = pre[curNode];
	}
	route.push_back(curNode);
	printf("%d\n", d[en]);
	printf("%d\n", (int) route.size());
	for (int i = route.size() - 1; i >= 0; --i)
	{
		printf("%d ", route[i]);
	}
}