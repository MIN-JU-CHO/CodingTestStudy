#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> inputs(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> inputs[i];
	}
	sort(inputs.begin(), inputs.end());

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		int start = 0, end = N - 1;
		while (start < end)
		{
			// skip itself
			if (start == i)
			{
				++start;
				continue;
			}
			else if (end == i)
			{
				--end;
				continue;
			}
			cout << inputs[start] << ' ' << inputs[end];
			// compare with sum
			if (inputs[start] + inputs[end] == inputs[i])
			{
				cout << "++" << '\n';
				// don't need to check duplicate
				++result;
				break;
			}
			else if (inputs[start] + inputs[end] < inputs[i])
			{
				++start;
			}
			else
			{
				--end;
			}
			cout << '\n';
		}
		cout << "--" << '\n';
	}
	cout << result;
}