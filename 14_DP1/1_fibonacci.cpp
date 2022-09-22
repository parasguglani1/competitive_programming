#include <bits/stdc++.h>
using namespace std;
int sol[1000] = {-1};

// 0 1 1 2 3 5 8 13 21
int getfibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    // int ans = getfibonacci(n - 1) + getfibonacci(n - 2);
    if (sol[n] = -1)
    {
        int ans = getfibonacci(n - 1) + getfibonacci(n - 2);
        return sol[n] = ans;
        // return ans;
    }
    return sol[n];
    // return ans;

    // return sol[n];
}

int fibRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibIterative(int n)
{
    int memo[n];
    memo[0] = 1;
    memo[1] = 1;
    //* sum of previous 2 elements sum
    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}
int main()
{
    int t;
    cin >> t;
    memset(sol, -1, sizeof(sol));
    while (t--)
    {
        sol[0] = 0;
        sol[1] = 1;
        int n;
        cin >> n;
        cout << getfibonacci(n) << endl;
    }
    return 0;
}
