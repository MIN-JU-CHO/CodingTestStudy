#include <stdio.h>
void hanoii(int n, int a, int b)
{
	if (n == 1)
	{
		printf("%d %d\n", a, b);
		return;
	}
	hanoii(n - 1, a, 6 - a - b);
	printf("%d %d\n", a, b);
	hanoii(n - 1, 6 - a - b, b);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	hanoii(n, 1, 3);
}