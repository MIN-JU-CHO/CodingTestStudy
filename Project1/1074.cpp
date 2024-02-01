#include<vector>
#include<stdio.h>

using namespace std;
int divide(int n, int x, int y)
{
	if (n == 0)
	{
		return 0;
	}
	int half = n / 2;
	if (x < half && y < half)
	{
		return divide(half, x, y);
	}
	else if (x < half && y >= half)
	{
		return half * half + divide(half, x, y - half);
	}
	else if (x >= half && y < half)
	{
		return 2 * half * half + divide(half, x - half, y);
	}
	else
	{
		return 3 * half * half + divide(half, x - half, y - half);
	}
}

int main(void)
{
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	printf("%d", divide(1<<n, r, c));
}