#define mod 1000000007
//  passing array as a parameter

int getWays(int n, int *sol)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    if (sol[n] == -1)
    {
        int ans = getWays(n - 1, sol) + getWays(n - 2, sol);
        return sol[n] = (ans % mod);
    }

    return sol[n];
}

int countDistinctWays(int nStairs)
{
    int sol[100001];
    memset(sol, -1, sizeof(sol));
    sol[1] = 0;
    sol[2] = 1;
    return getWays(nStairs, sol);
}
