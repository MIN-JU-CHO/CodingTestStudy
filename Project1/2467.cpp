#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<long long> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	int idx1 = 0, idx2 = N - 1, memIdx1 = idx1, memIdx2 = idx2;
	long long propVal = abs(arr[idx1] + arr[idx2]);
	while (idx1 != idx2)
	{
		// Update minimum propVal and memorize indexes
		long long calVal = arr[idx1] + arr[idx2];
		if (abs(calVal) < propVal)
		{
			propVal = abs(calVal);
			memIdx1 = idx1;
			memIdx2 = idx2;
		}
		if (calVal < 0)
		{
			++idx1;
		}
		else if(calVal > 0)
		{
			--idx2;
		}
		else
		{
			break;
		}
	}
	cout << arr[memIdx1] << " " << arr[memIdx2];
}