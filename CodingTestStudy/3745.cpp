// iostream 사용 O
// 실행 시간: 52ms, 사용 메모리: 2.8 KB
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
	int N;
	while (cin >> N)
	{
		vector<int> stock(N);
		vector<int> dp;
		for (int i = 0; i < N; ++i)
		{
			cin >> stock[i];
			int index = lower_bound(dp.begin(), dp.end(), stock[i]) - dp.begin();
			if (index == dp.size())
			{
				dp.push_back(stock[i]);
			}
			else
			{
				dp[index] = stock[i];
			}
		}
		printf("%d\n", (int)dp.size());
	}
}


// iostream 사용 X
// 입력 시간 초과 풀이
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//int N;
//using namespace std;
//int main(void)
//{
//	while (scanf_s("%d\n", &N))
//	{
//		vector<int> stock(N);
//		for (int i = 0; i < N;)
//		{
//			int input = -1;
//			scanf_s("%d", &input);
//			if (input != -1)
//			{
//				stock[i++] = input;
//			}
//		}
//		vector<int> dp;
//		for (int price : stock)
//		{
//			int index = lower_bound(dp.begin(), dp.end(), price) - dp.begin();
//			if (index == dp.size())
//			{
//				dp.push_back(price);
//			}
//			else
//			{
//				dp[index] = price;
//			}
//		}
//		printf("%d\n", (int)dp.size());
//	}
//}