/*

Knapsnack - Problem
Send Feedback
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task.
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
 */

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
// recursion
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    //* base case when there is no remaining weight or No coins
    if (maxWeight < 0 || n == 0)
    {
        return 0;
    }

    //* if current element's w(n-1) is more than remaining weight
    //* can not include into knapsack/bag
    if (weights[n - 1] > maxWeight)
    {
        return knapsack(weights, values, n - 1, maxWeight);
    }

    //* take current coin or not

    int option1 = values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1]);
    int option2 = knapsack(weights, values, n - 1, maxWeight);
    return max(option1, option2);
}

// memoization
int knapsackMem(int *weights, int *values, int n, int maxWeight, int** dp)
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
    ans = knapsackMem(weights, values, n - 1, maxWeight,dp);

    if (weights[n-1] <= maxWeight)
    {
        int ans1 = values[n-1] + knapsackMem(weights, values, n - 1, maxWeight - weights[n-1],dp);
        ans = max(ans1, ans);
    }
    dp[n][maxWeight] = ans;
    return ans;


}
// dp iterative
int knapsackDP(int *weights, int *values, int n, int maxWeight)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= maxWeight; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (weights[i - 1] <= j)
            {
                int remainingWeight = j - weights[i - 1];
                int remainingValue = dp[i - 1][remainingWeight];
                int totalValue = remainingValue + values[i - 1];
                if (totalValue > dp[i][j])
                {
                    dp[i][j] = totalValue;
                }
            }
        }
    }

    int ans = dp[n][maxWeight];
    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int knapSackDP2(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
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
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsackMem(weight, value, n, maxWeight,dp) << endl;
    // dp = vector<vector<int>>(n + 1, vector<int>(maxWeight + 1, -1));
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // vector<vector<int>> memo(n + 1, vector<int>(maxWeight + 1, -1));
    // int ans= knapSackDP2(maxWeight, weight, value, n);
    // int ans = knapsack(weight, value, n, maxWeight);

    // int ans = knapsackMem(weight, value, n, maxWeight,memo);
    // cout << ans << endl;

    return 0;
}
