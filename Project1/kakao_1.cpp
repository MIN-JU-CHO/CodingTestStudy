#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include<iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string, map<string, int>> info;
    map<string, int> points;
    for (auto elem : gifts)
    {
        stringstream ss(elem);
        ss.str(elem);
        string give, receive;
        ss >> give;
        ss >> receive;
        ++points[give];
        --points[receive];
        ++info[give][receive];
    }
    map<string, int> result;
    for (auto a : points)
    {
        cout << a.first << ": " << a.second << endl;
    }
    for (int i = 0; i < friends.size(); ++i)
    {
        string frnd = friends[i];
        for (int j = i + 1; j < friends.size(); ++j)
        {
            string with = friends[j];
            if (frnd == with)
            {
                continue;
            }
            if (info[frnd][with] > info[with][frnd])
            {
                cout << frnd << " from " << with << endl;
                ++result[frnd];
            }
            else if (info[frnd][with] < info[with][frnd])
            {
                cout << with << " from " << frnd << endl;
                ++result[with];
            }
            else
            {
                if (points[frnd] > points[with])
                {
                    cout << frnd << " from(points) " << with << endl;
                    ++result[frnd];
                }
                else if (points[frnd] < points[with])
                {

                    cout << with << " from(points) " << frnd << endl;
                    ++result[with];
                }
            }
        }
    }
    int answer = 0;
    for (auto elem : result)
    {
        cout << elem.first << ": " << elem.second << "\n";
        if (elem.second > answer)
        {
            answer = elem.second;
        }
    }
    return answer;
}

int main(void)
{
    vector<string> friends = { "muzi", "ryan", "frodo", "neo" },
                    gifts = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi",
                                "frodo muzi", "frodo ryan", "neo muzi" };
    cout << solution(friends, gifts);
    /*
frodo: 0
muzi: -3
neo: 1
ryan: 2
ryan from muzi
muzi from frodo
neo from muzi
frodo from ryan
ryan from(points) neo
neo from(points) frodo
frodo: 1
muzi: 1
neo: 2
ryan: 2
2
    */
}