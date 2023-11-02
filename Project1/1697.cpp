#include<iostream>
#include<queue>

using namespace std;
int main(void)
{
	int N, K;
	cin >> N;
	cin >> K;

	int pos[100002];
	fill(pos, pos + 100001, -1);

	int cur;
	queue<int> q;
	pos[N] = 0;
	q.push(N);
	for (int i = 0; i < 20; ++i)
	{
		cout <<i << "\t";
	}
	cout << endl;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		for (int i = 0; i < 20; ++i)
		{
			cout << pos[i] << "\t";
		}
		cout << endl;

		if (cur - 1 >= 0 && cur - 1 < 100002 && pos[cur - 1] == -1)
		{
			pos[cur - 1] = pos[cur] + 1;
			q.push(cur - 1);
		}

		if (cur + 1 >= 0 && cur + 1 < 100002 && pos[cur + 1] == -1)
		{
			pos[cur + 1] = pos[cur] + 1;
			q.push(cur + 1);
		}

		if (cur * 2 >= 0 && cur * 2 < 100002 && pos[cur * 2] == -1)
		{
			pos[cur * 2] = pos[cur] + 1;
			q.push(cur * 2);
		}

		if (cur - 1 == K || cur + 1 == K || cur * 2 == K)
		{
			cout << pos[K];
			return 0;
		}
	}
}