#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(void)
{
	int n, w, L;
	cin >> n >> w >> L;
	vector<int> trucks(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> trucks[i];
	}

	int weightOfBridge = 0, clock = 0;
	queue<int> curBridge;
	for (int i = 0; i < n; ++i)
	{
		while (true)
		{
			// there is sth to out
			if (curBridge.size() == w)
			{
				weightOfBridge -= curBridge.front();
				curBridge.pop();
			}
			// Out of weight to take in
			if (weightOfBridge + trucks[i] > L)
			{
				curBridge.push(0);
				++clock;
			}
			// Can Take in next truck
			else
			{
				curBridge.push(trucks[i]);
				weightOfBridge += trucks[i];
				++clock;
				break;
			}
		}
	}

	// Calculate last truck
	clock += w;
	cout << clock;
}