#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int days;
		cin >> days;
		vector<int> stocks(days);
		for (int i = 0; i < days; ++i)
		{
			cin >> stocks[i];
		}

		int max = stocks[days - 1];
		long long result = 0;
		for (int i = days - 2; i >= 0; --i)
		{
			if (stocks[i] <= max)
			{
				result += max - stocks[i];
			}
			else
			{
				max = stocks[i];
			}
		}
		cout << result << '\n';
	}
}