#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(void)
{
    int n = 2;
    vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
    vector<int> answer;
    vector<string> v;
    for (int i = 0; i < words.size(); ++i)
    {
        if (find(v.begin(), v.end(), words[i]) != v.end()
            || (i > 1 && words[i - 1].at(words[i - 1].size() - 1) != words[i].at(0)))
        {
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);
            answer.push_back((i + 1) / n);
        }
        else
        {
            v.push_back(words[i]);
        }
    }
    if (answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    cout << answer[0] << answer[1] << endl;
}