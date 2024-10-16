#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, startX, startY, inputNum;
	cin >> n >> m;
	vector<vector<int>> maps(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> inputNum;
			if (inputNum == 1)
			{
				inputNum = -1;
			}
			else if (inputNum == 2)
			{
				startX = i;
				startY = j;
				inputNum = 0;
			}
			maps[i][j] = inputNum;
		}
	}
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	while (!q.empty())
	{
		int curX = q.front().first, curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			// out of index
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
			{
				continue;
			}
			// visited or wall
			if (maps[nextX][nextY] != -1)
			{
				continue;
			}
			maps[nextX][nextY] = maps[curX][curY] + 1;
			q.push({ nextX, nextY });
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << maps[i][j] << " ";
		}
		cout << "\n";
	}
}