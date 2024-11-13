#include <iostream>
#include <queue>

using namespace std;
int cnt[10] = { 0,0,0,0,0,0,0,0,0,0 };
int main() {
    int N;
    cin >> N;
    queue<int> q;
    int answer = 0;
    while (N--)
    {
        int inputNum;
        cin >> inputNum;
        q.push(inputNum);
        ++cnt[inputNum];
        int category = 0;
        // search valid categories
        for (int i = 0; i < 10; ++i)
        {
            if (cnt[i] > 0)
            {
                ++category;
            }
        }
        // exceed limit: repeat delete from front
        while (category > 2)
        {
            int minus = q.front();
            q.pop();
            if (--cnt[minus] == 0)
            {
                --category;
            }
        }
        // can catch all valid cases -> find maximum
        answer = max(answer, (int)q.size());
    }
    cout << answer;
}