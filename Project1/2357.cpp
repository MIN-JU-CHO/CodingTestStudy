#include<cmath>
#include<cstdio>
#include <vector>


using namespace std;
int arr[100001];
vector<int> maxTree;
vector<int> minTree;

void Init(int node, int start, int end)
{
	if (start == end)
	{
		maxTree[node] = arr[start];
		minTree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	Init(node * 2, start, mid);
	Init(node * 2 + 1, mid + 1, end);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
	maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

// return {min, max}
pair<int, int> Find(int node, int curStart, int curEnd, int ansLeft, int ansRight)
{
	// out of range
	if (curStart > ansRight || curEnd < ansLeft)
	{
		//printf("[1]== %d %d\n", curStart, curEnd);
		return { 2147483647, 0 };
	}
	else if (curStart >= ansLeft && curEnd <= ansRight)
	{
		//printf("[2]== %d %d\n", curStart, curEnd);
		return { minTree[node], maxTree[node] };
	}
	else
	{
		//printf("[3]== %d %d ans: %d %d\n", curStart, curEnd, ansLeft, ansRight);
		pair<int, int> leftSeg, rightSeg;
		leftSeg = Find(node * 2, curStart, (curStart + curEnd) / 2, ansLeft, ansRight);
		rightSeg = Find(node * 2 + 1, (curStart + curEnd) / 2 + 1, curEnd, ansLeft, ansRight);
		return { min(leftSeg.first, rightSeg.first), max(leftSeg.second, rightSeg.second) };
	}
}

int main(void)
{
	int N, M;
	scanf_s("%d %d", &N, &M);
	maxTree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
	minTree = vector<int>(1 << ((int)ceil(log2(N)) + 1));

	for (int i = 1; i <= N; ++i)
	{
		scanf_s("%d", &arr[i]);
	}
	Init(1, 1, N);
	while (M--)
	{
		int a, b;
		scanf_s("%d %d", &a, &b);
		pair<int, int> result = Find(1, 1, N, a, b);
		printf("%d %d\n", result.first, result.second);
	}
}