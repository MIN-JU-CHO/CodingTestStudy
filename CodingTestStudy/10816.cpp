#include<stdio.h>
#include<unordered_map>

using namespace std;
int main(void)
{
	int N, M;
	scanf_s("%d", &N);
	unordered_map<int, int> numCards;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		scanf_s("%d", &temp);
		numCards[temp] = numCards[temp] + 1;
	}
	scanf_s("%d", &M);
	for (int i = 0;i < M; ++i)
	{
		int temp;
		scanf_s("%d", &temp);
		printf("%d ", numCards[temp]);
	}
}