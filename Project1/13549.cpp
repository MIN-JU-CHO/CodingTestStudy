#include<iostream>
#include<queue>

using namespace std;
int N, K;
int race[100002];
queue<int> q;
void teleport(int pos, int value)
{
	while (pos <= 100001 && race[pos] == -1)
	{
		race[pos] = value;
		q.push(pos);
		// arrive
		if (pos == K)
		{
			return;
		}
		pos *= 2;
	}
}
int main(void)
{
	cin >> N;
	cin >> K;
	fill(race, race + 100001, -1);
	int pos;
	q.push(N);
	race[N] = 0;
	teleport(N * 2, 0);
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		if (pos + 1 >= 0 && pos + 1 <= 100001 && race[pos + 1] == -1)
		{
			race[pos + 1] = race[pos] + 1;
			q.push(pos + 1);
			teleport((pos + 1) * 2, race[pos + 1]);
		}
		if (pos - 1 >= 0 && pos - 1 <= 100001 && race[pos - 1] == -1)
		{
			race[pos - 1] = race[pos] + 1;
			q.push(pos - 1);
			teleport((pos - 1) * 2, race[pos - 1]);
		}
		/*
		queue<int> tempQ;
		int size = q.size();
		for (int i = 0; i < size;++i)
		{
			cout << q.front() << "/";
			tempQ.push(q.front());
			q.pop();
		}
		for (int i = 0; i < size;++i)
		{
			q.push(tempQ.front());
			tempQ.pop();
		}
		cout << endl;
		*/
	}
	cout << race[K];
}