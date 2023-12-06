#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> info;
    for(int i=0; i<n; ++i)
    {
        int stime, ttime;
        scanf("%d %d", &stime, &ttime);
        info.push_back({ttime, stime});
    }
    // Terminal Time 기준으로 정렬
    sort(info.begin(), info.end());

    // 마지막 타임과 겹치지 않을 때 마지막 타임으로 넣기
    vector<pair<int, int>> result;
    result.push_back(info[0]);
    for(int i=1; i<n; ++i)
    {
        if (result.back().first <= info[i].second)
        {
            result.push_back(info[i]);
        }
    }
    printf("%d", (int)result.size());
}