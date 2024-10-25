#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
int main(void)
{
	int N;
	scanf_s("%d", &N);

	// previous candidate
	bool arr[1001];
	fill(arr, arr + 1000, true);
	for (int i = 123; i <= 987; ++i)
	{
		string pivot = to_string(i);
		if (pivot[0] == pivot[1] || pivot[0] == pivot[2] || pivot[2] == pivot[1])
		{
			arr[i] = false;
		}
		if (pivot[0] - '0' == 0 || pivot[1] - '0' == 0 || pivot[2] - '0' == 0)
		{
			arr[i] = false;
		}
	}

	while (N--)
	{
		int inputNum, strike, ball;
		scanf_s("%d %d %d", &inputNum, &strike, &ball);

		string inputStr = to_string(inputNum);
		for (int i = 123; i <= 987; ++i)
		{
			string pivot = to_string(i);
			int tempStrike = 0, tempBall = 0;
			for (int j = 0; j < 3; ++j)
			{
				if (inputStr[j] == pivot[j])
				{
					++tempStrike;
					continue;
				}
				for (int k = 0; k < 3; ++k)
				{
					if (pivot[j] == inputStr[k])
					{
						++tempBall;
					}
				}
			}
			if (strike != tempStrike || ball != tempBall)
			{
				arr[i] = false;
			}
		}
	}

	int result = 0;
	for (int i = 123; i <= 987; ++i)
	{
		if (arr[i] == true)
		{
			++result;
		}
	}
	printf("%d", result);
}