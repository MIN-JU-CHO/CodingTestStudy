#include <cstdio>
#include <vector>

using namespace std;
int main(void)
{
    int N;
    scanf("%d", &N);
    vector<int> stick(N);
    int cnt[10] = { 0,0,0,0,0,0,0,0,0,0 };
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &stick[i]);
    }
    // bpth two pointers start from first
    int start = 0, end = 0, answer = 1;
    ++cnt[stick[start]];
    while (start < N)
    {
        while (end < N)
        {
            ++end;
            if (end >= N)
            {
                break;
            }
            ++cnt[stick[end]];

            // search valid categories
            int category = 0;
            for (int i = 0; i < 10; ++i)
            {
                if (cnt[i] > 0)
                {
                    ++category;
                }
            }
            // bad case: memorize max from previous case(valid)
            if (category > 2)
            {
                --cnt[stick[end]];
                --end;
                answer = max(answer, end - start + 1);
                break;
            }
            // good case: memorize max and move to next
            else
            {
                answer = max(answer, end - start + 1);
            }
        }
        --cnt[stick[start]];
        ++start;
    }
    printf("%d", answer);
}