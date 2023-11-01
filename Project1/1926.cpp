#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	int num = 0, area = 0;
	vector<vector<int>> board;
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (int x = 0; x < N;++x)
	{
		vector<int> row(M);
		for (int y = 0;y < M;++y)
		{
			cin >> row[y];
		}
		board.push_back(row);
	}

	int dx[] = { -1,0,0,1 };
	int dy[] = { 0,-1,1,0 };
	int nx = 0, ny = 0;
	int count_area = 0;
	pair<int, int> temp;
	
	for (int x = 0; x < N;++x)
	{
		for (int y = 0;y < M;++y)
		{
			if (visited[x][y] || board[x][y] == 0)
			{
				continue;
			}
			queue<pair<int, int>> q;
			count_area = 0;
			q.push({ x,y });
			visited[x][y] = true;
			while (!q.empty())
			{
				temp = q.front();	q.pop();
				++count_area;

				for (int i = 0; i < 4; ++i)
				{
					nx = temp.first + dx[i];
					ny = temp.second + dy[i];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					{
						continue;
					}
					if (visited[nx][ny] || board[nx][ny] == 0)
					{
						continue;
					}
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
			++num;
			area = max(area, count_area);
		}
	}
	cout << num << endl << area;
}
