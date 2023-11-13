#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int main(void)
{
	vector<int> arr = { 1, 2, 3, 5, 6 };
	cout << lower_bound(arr.begin(), arr.end(), 4) - arr.begin();
}