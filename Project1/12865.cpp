#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
    int N, K;
    long long W, V;
    cin >> N >> K;
    vector<long long> dp(K + 1, 0);
    for(int i=1; i<=N; ++i)
    {
        cin >> W >> V;
        if(W>K)
        {
            continue;
        }
        for(int j=K; j>=1; --j)
        {
            if(j+W <= K && dp[j]!=0)
            {
                dp[j+W] = max(dp[j]+V, dp[j+W]);
            }
        }
        dp[W]=max(dp[W], V);
    }
    cout << *max_element(dp.begin(), dp.end());
}