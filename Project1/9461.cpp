#include<iostream>

using namespace std;
int main(void)
{
    long long P[101];
    fill(P, P+101, 0);
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    int T, N;
    cin >> T;
    while(T--)
    {
        cin >>N;
        for(int i=4; i<=N; ++i)
        {
            if(P[i]==0)
            {
                P[i] = P[i-3]+P[i-2];
            }
        }
        cout << P[N] <<endl;
    }
}