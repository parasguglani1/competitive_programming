
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;


// memoization
int knapsackMem(int *weights, int *values, int n, int maxWeight)
{
    if (maxWeight < 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }

    int ans = 0;
    ans = knapsackMem(weights, values, n - 1, maxWeight);

    if (weights[n - 1] <= maxWeight)
    {
        int ans1 = values[n - 1] + knapsackMem(weights, values, n - 1, maxWeight - weights[n - 1]);
        ans = max(ans1, ans);
    }
    dp[n][maxWeight] = ans;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int *weight = new int[n];
    int *value = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int maxWeight;
    cin >> maxWeight;

    dp = vector<vector<int>>(n + 1, vector<int>(maxWeight + 1, -1));
    cout << knapsackMem(weight, value, n, maxWeight) << endl;


    return 0;
}
