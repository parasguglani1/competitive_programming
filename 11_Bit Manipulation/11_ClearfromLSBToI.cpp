#include <bits/stdc++.h>
using namespace std;
// remove all set bits from right to i
int clearfromLSB(int n, int i)
{
    int a = 1 << (i + 1);
    a--;
    int mask = ~a;

    // mask = ~((1 << i + 1) - 1); // one liner
    int ans = mask & n;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int i;
    cin >> i;
    int m = clearfromLSB(n, i);
    cout << m << endl;

    return 0;
}