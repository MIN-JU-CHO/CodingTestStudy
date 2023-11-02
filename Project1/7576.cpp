#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;
int main(void)
{
	int M, N;
	scanf_s("%d", &M);
	scanf_s("%d", &N);

	vector<vector<int>> tomato(N);
	vector<int> temp;
	int element;
	queue<pair<int, int>> q, tempQ;
	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			scanf_s("%d", &element);
			temp.push_back(element);
			if (element == 1)
			{
				tempQ.push({ x, y });
			}
		}
		tomato[x] = temp;
		temp.clear();
	}

	int dx[] = { -1, 0, 0, 1 };
	int dy[] = { 0, -1, 1, 0 };
	pair<int, int> coord;
	int count = -1;
	while (!tempQ.empty())
	{
		while (!tempQ.empty())
		{
			q.push(tempQ.front());
			tempQ.pop();
		}
		if (q.size() > 0)
		{
			++count;
		}
		while (!q.empty())
		{
			coord = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				if (coord.first + dx[i] < 0 || coord.first + dx[i] >= N
					|| coord.second + dy[i] < 0 || coord.second + dy[i] >= M)
				{
					continue;
				}
				if (tomato[coord.first + dx[i]][coord.second + dy[i]] != 0)
				{
					continue;
				}
				tempQ.push({ coord.first + dx[i] , coord.second + dy[i] });
				tomato[coord.first + dx[i]][coord.second + dy[i]] = 1;
			}
		}
	}
	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			if (tomato[x][y] == 0)
			{
				count = -1;
				break;
			}
		}
		if (count == -1)
		{
			break;
		}
	}
	printf("%d", count);
}