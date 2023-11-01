#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int counts[2] = { 0, 0 };

void div_half(int x, int y, int n)
{
	if (n == 1)
	{
		++counts[paper[y][x]];
	}
	else
	{
		int pivot = paper[y][x];
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
		if (isPivot)
		{
			++counts[paper[y][x]];
			return;
		}
		else
		{
			div_half(x, y, n / 2);
			div_half(x + n / 2, y, n / 2);
			div_half(x, y + n / 2, n / 2);
			div_half(x + n / 2, y + n / 2, n / 2);
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		vector<int> input(N);
		for (int j = 0; j < N; ++j)
		{
			cin >> input[j];
		}
		paper.push_back(input);
	}
	div_half(0, 0, N);
	cout << counts[0] << endl << counts[1] << endl;
}