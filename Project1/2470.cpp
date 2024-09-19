#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int p1 = 0, p2 = N - 1, r1 = p1, r2 = p2;
	int minimum = abs(arr[p1] + arr[p2]);
	while (p1 < p2)
	{
		int plus = arr[p1] + arr[p2];
		if (abs(plus) < minimum)
		{
			minimum = abs(plus);
			r1 = p1;
			r2 = p2;
		}
		if (plus == 0)
		{
			break;
		}
		else if (plus > 0)
		{
			--p2;
		}
		else
		{
			++p1;
		}
	}
	cout << arr[r1] << " " << arr[r2];
}