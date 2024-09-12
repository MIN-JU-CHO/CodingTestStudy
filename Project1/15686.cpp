#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;
int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> chickenMap(N, vector<int>(N));
	vector<pair<int, int>> houseInfo;
	vector<pair<int, int>> chickenInfo;

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			cin >> chickenMap[r][c];
			if (chickenMap[r][c] == 1)
			{
				houseInfo.push_back({ r, c });
			}
			else if (chickenMap[r][c] == 2)
			{
				chickenInfo.push_back({ r, c });
			}
		}
	}

	// Setting first case of selecting chicken
	vector<int> allCases(chickenInfo.size(), 1);
	for (int i = 0; i < chickenInfo.size() - M; ++i)
	{
		allCases[i] = 0;
	}

	// Worst Case (Maximum)
	int answer = 2 * N * houseInfo.size();

	// Try All Cases
	do
	{
		cout << "{ ";
		for (int i = 0; i < allCases.size(); ++i)
		{
			cout << allCases[i] << ", ";
		}
		cout << "}" << endl;
		vector<vector<int>> tempMap = chickenMap;
		vector<int> dist(houseInfo.size(), 2*N);

		for (int i = 0; i < allCases.size(); ++i)
		{
			// Update Min Distance by Each Chicken
			if (allCases[i] == 1)
			{
				cout << "Valid Chicken Coord: " << chickenInfo[i].first << ", " << chickenInfo[i].second << endl;
				for (int idx = 0; idx < dist.size(); ++idx)
				{
					pair<int, int> coord = houseInfo[idx];
					dist[idx] = min(dist[idx],
						abs(coord.first - chickenInfo[i].first) + abs(coord.second - chickenInfo[i].second));
					
					cout << "Update Dist: (" << coord.first << ", " << coord.second << "): " << abs(coord.first - chickenInfo[i].first) + abs(coord.second - chickenInfo[i].second) << endl;

				}
			}
		}
		answer = min(answer, accumulate(dist.begin(), dist.end(), 0));
	} while (next_permutation(allCases.begin(), allCases.end()));
	cout << answer;
}