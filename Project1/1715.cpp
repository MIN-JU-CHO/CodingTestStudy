#include <stdio.h>
#include <queue>
#include <functional>

using namespace std;
int main(void)
{
    int n, x;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--)
    {
        scanf("%d", &x);
        pq.push(x);
    }
    int sum = 0;
    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    printf("%d", sum);
}