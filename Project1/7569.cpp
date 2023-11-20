#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int main(void)
{
	int M, N, H;
	cin >> M;
	cin >> N;
	cin >> H;
	queue<vector<int>> nextQ;
	vector<vector<vector<int>>> boxes;
	for (int h = 0; h < H; ++h)
	{
		vector<vector<int>> plane;
		for (int i = 0; i < N; ++i)
		{
			vector<int> row(M);
			for (int j = 0; j < M; ++j)
			{
				cin >> row[j];
				if (row[j] == 1)
				{
					nextQ.push({ h, i, j });
				}
			}
			plane.push_back(row);
		}
		boxes.push_back(plane);
	}

	int result = 0;
	if (nextQ.size() == M * N * H)
	{
		cout << 0;
		return 0;
	}

	int dh[6] = { 0, 0, 0, 0, -1, 1 };
	int dx[6] = { -1, 1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, -1, 1, 0, 0 };

	while (!nextQ.empty())
	{
		queue<vector<int>> tempQ;
		while (!nextQ.empty())
		{
			auto elem = nextQ.front();
			nextQ.pop();
			tempQ.push(elem);
		}
		while(!tempQ.empty())
		{
			int h, x, y;
			h = tempQ.front()[0];
			x = tempQ.front()[1];
			y = tempQ.front()[2];
			tempQ.pop();
			for (int k = 0; k < 6; ++k)
			{
				int nh = h + dh[k];
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nh < 0 || nh >= H || nx < 0 || nx >= N || ny < 0 || ny >= M)
				{
					continue;
				}
				if (boxes[nh][nx][ny] == -1 || boxes[nh][nx][ny] == 1)
				{
					continue;
				}
				boxes[nh][nx][ny] = 1;
				nextQ.push({ nh, nx, ny });
			}
		}
		if (!nextQ.empty())
		{
			++result;
		}
	}

	for (int h = 0; h < H; ++h)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (boxes[h][i][j] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << result;
}