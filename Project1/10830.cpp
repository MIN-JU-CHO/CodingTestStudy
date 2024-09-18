#include <iostream>
#include <vector>

using namespace std;
int N;
vector<vector<int>> matrix;
vector<vector<int>> TimeMatrix(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> result(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			long long temp = 0;
			for (int k = 0; k < N; ++k)
			{
				temp += A[i][k] * B[k][j];
			}
			result[i][j] = temp % 1000;
		}
	}
	return result;
}

vector<vector<int>> TimeMode(long long depth)
{
	if (depth == 0)
	{
		vector<vector<int>>tt(N, vector<int>(N, 0)) ;
		for (int i = 0; i < N; ++i)
		{
			tt[i][i] = 1;
		}
		return tt;
	}
	vector<vector<int>> intermediate = TimeMode(depth / 2);
	if (depth % 2 == 0)
	{
		return TimeMatrix(intermediate, intermediate);
	}
	else
	{
		return TimeMatrix(TimeMatrix(intermediate, intermediate), matrix);
	}
}

int main(void)
{
	long long B;
	cin >> N >> B;

	matrix.resize(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	vector<vector<int>> result = TimeMode(B);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//int N, long long B;
//long long ans[5][5];
//long long A[5][5];
//
//void TimeMatrix(long long X[5][5], long long Y[5][5])
//{
//	long long temp[5][5];
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			temp[i][j] = 0;
//			for (int k = 0; k < N; ++k)
//			{
//				temp[i][j] += X[i][k] * Y[k][j];
//			}
//			temp[i][j] = temp[i][j] % 1000;
//		}
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			X[i][j] = temp[i][j];
//		}
//	}
//}
//
//int main(void)
//{
//	cin >> N >> B;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cin >> A[i][j];
//		}
//		ans[i][i] = 1;
//	}
//
//	while (B > 0)
//	{
//		if (B % 2 == 1)
//		{
//			TimeMatrix(ans, A);
//		}
//		TimeMatrix(A, A);
//		B /= 2;
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			cout << ans[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}