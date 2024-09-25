#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> team(2 * N);
    for (int i = 0; i < 2 * N; ++i)
    {
        cin >> team[i];
    }
    sort(team.begin(), team.end());
    int minimum = team[0] + team[2 * N - 1];
    for (int i = 0; i < N; ++i)
    {
        minimum = min(minimum, team[i] + team[2 * N - 1 - i]);
    }
    cout << minimum;
}