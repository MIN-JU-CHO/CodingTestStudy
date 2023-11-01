#include <vector>
#include <stdio.h>

using namespace std;

vector<vector<char>> paper;
vector<char> result;
void div_half(int x, int y, int n)
{
	if (n == 1)
	{
		result.push_back(paper[y][x]);
		return;
	}
	else
	{
		char pivot = paper[y][x];
		bool isPivot = true;
		for (int i = y; i < y + n; ++i)
		{
			for (int j = x; j < x + n; ++j)
			{
				if (paper[i][j] != pivot)
				{
					isPivot = false;
					break;
				}
			}
			if (!isPivot)
			{
				break;
			}
		}
		if (!isPivot)
		{
			result.push_back('(');
			div_half(x, y, n / 2);
			div_half(x + n / 2, y, n / 2);
			div_half(x, y + n / 2, n / 2);
			div_half(x + n / 2, y + n / 2, n / 2);
			result.push_back(')');
		}
		else
		{
			result.push_back(paper[y][x]);
			return;
		}
	}
}


int main(void)
{
	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		vector<char> row(N);
		for (int j = 0; j < N;)
		{
			char c;
			scanf_s("%c", &c);
			if (c != '\n' && c != '\0')
			{
				row[j++] = c;
			}
		}
		paper.push_back(row);
	}

	div_half(0, 0, N);
	for (char c : result)
	{
		printf("%c", c);
	}
}