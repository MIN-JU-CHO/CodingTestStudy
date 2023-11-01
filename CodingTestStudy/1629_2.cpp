#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, d = 1;
    cin >> a >> b >> c;
    while (1 < b)
    {
        if (b % 2 == 1)
            d = (d * a) % c;

        a = (a * a) % c;
        b /= 2;
    }
    cout << (a * d) % c;
}