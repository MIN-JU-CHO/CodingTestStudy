// solution from https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/13549.cpp
#include <iostream>
#include <queue>
using namespace std;

const int LMT = 100001;
int board[LMT + 2];
int sis, bro;
queue<int> Q;
void teleport(int num) {
    int tmp = num;
    if (!tmp) return;
    while (tmp < LMT && !board[bro]) {
        if (!board[tmp]) {
            board[tmp] = board[num];
            Q.push(tmp);
            if (tmp == bro) return;
        }
        tmp <<= 1;
    }
}
int main(void) {

    cin >> sis >> bro;
    board[sis] = 1;
    Q.push(sis);
    teleport(sis);
    while (!board[bro]) {
        int v = Q.front(); Q.pop();

        vector<int> nvLst = { v + 1, v - 1 };
        for (int nv : nvLst) {
            if (nv < 0 || LMT <= nv) continue;
            if (board[nv]) continue;
            board[nv] = board[v] + 1;
            Q.push(nv);
            teleport(nv);
        }

        queue<int> tempQ;
        int size = Q.size();
        for (int i = 0; i < size;++i)
        {
            cout << Q.front() << "/";
            tempQ.push(Q.front());
            Q.pop();
        }
        for (int i = 0; i < size;++i)
        {
            Q.push(tempQ.front());
            tempQ.pop();
        }
        cout << endl;

    }
    cout << board[bro] - 1;
}