#include <stdio.h>
#include <queue>
#include <stdlib.h>

using namespace std;

int N, K;
int visited[100002];
queue<int> q;

void teleport(int cur, int sec)
{
    while (cur <= 100000 && visited[cur] == -1)
    {
        visited[cur] = sec;
        q.push(cur);
        if (cur == K)
        {
            printf("%d", visited[cur]);
            exit(0);
        }
        cur *= 2;
    }
}

int main(void)
{
    scanf("%d %d", &N, &K);
    fill(visited, visited + 100001, -1);
    int d[2] = { -1, 1 };

    teleport(N, 0);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        //printf("Cur: %d\n", cur);
        for (int offset : d)
        {
            if (cur + offset < 0 || cur + offset >= 100002)
            {
                continue;
            }
            if (visited[cur + offset] != -1)
            {
                continue;
            }
            teleport(cur + offset, visited[cur] + 1);
        }
    }
    printf("%d", visited[K]);
}