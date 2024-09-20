#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
int main(void)
{
	int N;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}
	sort(P.begin(), P.end());
	int result = 0;
	for (auto iter = P.begin(); iter != P.end(); ++iter)
	{
		result += accumulate(P.begin(), iter, 0);
	}
	result += accumulate(P.begin(), P.end(), 0);
	cout << result;
}