#include<stdio.h>

int N, M;
int A[1000000], B[1000000], C[2000000];
int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &B[i]);
	}
	int a = 0, b = 0, c = 0;
	while (a < N && b < M)
	{
		if (A[a] <= B[b])
		{
			C[c++] = A[a++];
		}
		else
		{
			C[c++] = B[b++];
		}
	}
	if (a >= N)
	{
		while (b < M)
		{
			C[c++] = B[b++];
		}
	}
	else
	{
		while (a < N)
		{
			C[c++] = A[a++];
		}
	}
	for (int i = 0; i < c; ++i)
	{
		printf("%d ", C[i]);
	}
}