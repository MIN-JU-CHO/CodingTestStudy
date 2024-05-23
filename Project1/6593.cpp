// 실행 시간: 4ms, 메모리: 2160KB
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	while (true)
	{
		int L, R, C;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
		{
			break;
		}
		queue<vector<int>> q;
		vector<vector<vector<char>>> LRC(L, vector<vector<char>>(R, vector<char>(C)));
		vector<vector<vector<int>>> distance(L, vector<vector<int>>(R, vector<int>(C, -1)));
		for (int i = 0; i < L; ++i)
		{
			for (int x = 0; x < R; ++x)
			{
				for (int y = 0; y < C; ++y)
				{
					cin >> LRC[i][x][y];
					if (LRC[i][x][y] == 'S')
					{
						q.push({ i, x, y });
						distance[i][x][y] = 0;
					}
				}
			}
		}
		vector<int> dl = { -1, 1, 0, 0, 0, 0 },
			dx = { 0, 0, -1, 1, 0, 0 },
			dy = { 0, 0, 0, 0, -1, 1 };
		bool isArrived = false;
		while (!q.empty() && isArrived == false)
		{
			int l = q.front()[0];
			int r = q.front()[1];
			int c = q.front()[2];
			q.pop();

			for (int i = 0; i < 6; ++i)
			{
				int nextLev = l + dl[i];
				int nextRow = r + dx[i];
				int nextCol = c + dy[i];
				// Out of range
				if (nextLev < 0 || nextLev >= L
					|| nextRow < 0 || nextRow >= R
					|| nextCol < 0 || nextCol >= C)
				{
					continue;
				}
				// Arrive to the End
				if (LRC[nextLev][nextRow][nextCol] == 'E')
				{
					cout<< "Escaped in "<< distance[l][r][c] + 1 <<" minute(s).\n";
					isArrived = true;
					break;
				}
				// Can't Move - Visted or Wall
				if (LRC[nextLev][nextRow][nextCol] != '.')
				{
					continue;
				}
				// Make visited and insert into queue
				distance[nextLev][nextRow][nextCol] = distance[l][r][c] + 1;
				LRC[nextLev][nextRow][nextCol] = '#';
				q.push({ nextLev, nextRow, nextCol });
			}
		}
		if (isArrived == false)
		{
			cout << "Trapped!\n";
		}
	}
}