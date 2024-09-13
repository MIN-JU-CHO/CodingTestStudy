#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int minNum = arr[N - 1] - arr[0];
	int start = 0, end = 0;
	while (start < N && end < N)
	{
		if (arr[end] - arr[start] >= M)
		{
			minNum = min(minNum, arr[end] - arr[start]);
			++start;
		}
		else
		{
			++end;
		}
	}
	cout << minNum;
}