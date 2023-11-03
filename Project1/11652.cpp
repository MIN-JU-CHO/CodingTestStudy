#include <stdio.h>
#include <map>

using namespace std;
int main(void)
{
	int N;
	scanf_s("%d", &N);
	map<long long, int> count;
	long long input;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%lld", &input);
		++count[input];
	}
	int max_count = 0;
	long long answer = count.begin()->first;
	for (auto iter = count.begin(); iter != count.end(); ++iter)
	{
		if (max_count < iter->second)
		{
			max_count = iter->second;
			answer = iter->first;
		}
	}
	printf("%lld", answer);
}