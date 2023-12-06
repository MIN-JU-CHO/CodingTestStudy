#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i=0; i<n; ++i)
    {
        cin >> A[i];
    }
    for (int i=0; i<n; ++i)
    {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int result = 0;
    for (int i=0; i<n; ++i)
    {
        result += A[i] * B[n-1-i];
    }
    cout << result;
}