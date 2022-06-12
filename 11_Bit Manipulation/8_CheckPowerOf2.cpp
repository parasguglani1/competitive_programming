#include <bits/stdc++.h>
using namespace std;
bool checkPower(int n)
{
    return (n & (n - 1)) == 0;
}

int main()
{
    int n;
    cin >> n;
    if (checkPower(n))
    {
        cout << "power of 2" << endl;
    }
    else
    {
        cout << "not" << endl;
    }
    // cout << n << endl;

    return 0;
}

