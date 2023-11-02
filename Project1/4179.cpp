#include<queue>
#include<vector>
#include<iostream>

using namespace std;
int main(void)
{
	int R, C;
	cin >> R;
	cin >> C;
	
	queue<pair<int, int>> fq, jq;
	vector<vector<int>> fire(R, vector<int>(C, -1));
	vector<vector<int>> jihoon(R, vector<int>(C, -1));
	vector<string> maze(R);
	string input;
	for (int r = 0; r < R; ++r)
	{
		cin >> input;
		for (int c = 0; c < C; ++c)
		{
			if (input[c] == 'J')
			{
				jq.push({ r,c });
				jihoon[r][c] = 1;
			}
			else if (input[c] == 'F')
			{
				fq.push({ r,c });
				fire[r][c] = 1;
			}
		}
		maze[r] = input;
	}

	int dx[] = { -1,0,0,1 };
	int dy[] = { 0,-1,1,0 };
	int nx, ny, curX, curY;
	pair<int, int> coord;
	while (!fq.empty())
	{
		coord = fq.front();
		fq.pop();
		curX = coord.first;
		curY = coord.second;
		for (int i = 0; i < 4; ++i)
		{
			nx = curX + dx[i];
			ny = curY + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				continue;
			}
			if (maze[nx][ny] == '#' || fire[nx][ny] >= 1)
			{
				continue;
			}
			fire[nx][ny] = fire[curX][curY] + 1;
			fq.push({ nx , ny });
		}
	}

	while (!jq.empty())
	{
		coord = jq.front();
		jq.pop();
		curX = coord.first;
		curY = coord.second;
		for (int i = 0; i < 4; ++i)
		{
			nx = curX + dx[i];
			ny = curY + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << jihoon[curX][curY];	// escape
				return 0;
			}
			if (maze[nx][ny] == '#' || jihoon[nx][ny] >= 1)
			{
				continue;
			}
			if (fire[nx][ny] != -1	// fire has valid value
				&& fire[nx][ny] <= jihoon[curX][curY] + 1)	// expire fire second
			{
				continue;
			}
			jihoon[nx][ny] = jihoon[curX][curY] + 1;
			jq.push({ nx , ny });
		}
	}

	
	cout << "IMPOSSIBLE";
}