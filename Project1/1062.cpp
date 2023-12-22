#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k;
vector<string> words;
vector<bool> alphabet(26, false);
int result = 0;

void dfs(int idx, int depth)
{
    if(depth == 0)
    {
        int cnt = 0;
        for (string word : words)
        {
            // 단어별 습득 가능 여부
            bool canTeach = true;
            for(char alp : word)
            {
                if(!alphabet[alp - 'a'])
                {
                    canTeach = false;
                    break;
                }
            }
            if (canTeach)
            {
                ++cnt;
            }
        }
        result = max(result, cnt);
        // 가능한 최대의 경우면 바로 출력
        if (result == n)
        {
            cout << n;
            exit(0);
        }
        return;
    }
    // back-tracking
    for (int i=idx; i<26; ++i)
    {
        if(alphabet[i])
        {
            continue;
        }
        alphabet[i] = true;
        dfs(i+1, depth-1);
        alphabet[i] = false;
    }
}

int main(void)
{
    cin >> n >> k;
    // alphabet 기본 개수보다 적을 때
    if(k < 5)
    {
        cout << 0;
        return 0;
    }
    
    string word;
    for (int i=0; i<n; ++i)
    {
        cin >> word;
        words.push_back(word.substr(4, word.size() - 8));
    }
    
    alphabet['a'-'a'] = true;
    alphabet['n'-'a'] = true;
    alphabet['t'-'a'] = true;
    alphabet['i'-'a'] = true;
    alphabet['c'-'a'] = true;

    dfs(0, k-5);
    cout << result;
}