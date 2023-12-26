#include <stdio.h>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;
class cmp
{
public:
    bool operator() (int a, int b)
    {
        if (abs(a) != abs(b))
        {
            return abs(a) > abs(b);
        }
        else
        {
            return a > 0 && b < 0;
        }
    }
};

int main(void)
{
    int n, x;
    scanf("%d", &n);
    priority_queue<int, vector<int>, cmp> pq;
    while(n--)
    {
        scanf("%d", &x);
        if(x == 0)
        {
            if(pq.empty())
            {
                printf("0\n");
                continue;
            }
            printf("%d\n", pq.top());
            pq.pop();
            continue;
        }
        pq.push(x);
    }
}