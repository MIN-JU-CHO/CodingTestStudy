#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> matrix1(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> matrix1[i][j];
		}
	}

	int M1, K;
	cin >> M1 >> K;
	vector<vector<int>> matrix2(M1, vector<int>(K));
	for (int i = 0; i < M1; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			cin >> matrix2[i][j];
		}
	}

	vector<vector<int>> result(N, vector<int>(K));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			int temp = 0;
			for (int r = 0; r < M; ++r)
			{
				temp += matrix1[i][r] * matrix2[r][j];
			}
			result[i][j] = temp;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}