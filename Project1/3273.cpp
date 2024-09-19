#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, x;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cin >> x;

	int p1 = 0, p2 = n - 1, cnt = 0;
	while (p1 < p2)
	{
		if (arr[p1] + arr[p2] == x)
		{
			++cnt;
			++p1;
		}
		else if (arr[p1] + arr[p2] < x)
		{
			++p1;
		}
		else
		{
			--p2;
		}
	}

	cout << cnt;
}