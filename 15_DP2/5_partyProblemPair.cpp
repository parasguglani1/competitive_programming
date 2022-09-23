
// pair approach memoization

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> solve_dp(int n, int w, int fee[], int fun[])
{
    //* no parties
    if (n == 0)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    // for array
    pair<int, int> zero_pair = make_pair(0, 0);
    //* 2D vector of pair
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(w + 1, zero_pair));

    //* fee, fun
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            //* fee is less than or equal to budget
            if (fee[i - 1] <= j)
            {
                pair<int, int> c1;
                c1.first = fee[i - 1] + dp[i - 1][j - fee[i - 1]].first;   // fee
                c1.second = fun[i - 1] + dp[i - 1][j - fee[i - 1]].second; // fun

                //* not take party situation(above sell)
                pair<int, int> c2 = dp[i - 1][j];

                if (c1.second > c2.second)
                {
                    dp[i][j] = c1;
                }
                else if (c1.second < c2.second)
                    dp[i][j] = c2;
                else
                {
                    if (c1.first <= c2.first)
                    {
                        dp[i][j] = c1;
                    }
                    else
                        dp[i][j] = c2;
                }
            }
            else
            {

                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (int i = 0; i < n+1; i++)
    // {
    // 	for (int j = 0; j < w+1; j++)
    // 	{
    //         cout << dp[i][j].first << "," << dp[i][j].second << " ";
    // 	}
    //     cout << endl;
    // }

    return dp[n][w];
}

pair<int, int> maxFun(int *entry, int *fun, int budget, int n, pair<int, int> **dp)
{
    if (n == 0)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    if (dp[budget][n].first != -1 && dp[budget][n].second != -1)
    {
        return dp[budget][n];
    }

    if (entry[0] > budget)
    {
        dp[budget][n] = maxFun(entry + 1, fun + 1, budget, n - 1, dp);
    }
    else
    {
        pair<int, int> ans1 = maxFun(entry + 1, fun + 1, budget - entry[0], n - 1, dp);
        ans1.first += entry[0];
        ans1.second += fun[0];
        pair<int, int> ans2 = maxFun(entry + 1, fun + 1, budget, n - 1, dp);
        if (ans1.second > ans2.second)
        {
            dp[budget][n] = ans1;
        }
        else if (ans2.second > ans1.second)
        {
            dp[budget][n] = ans2;
        }
        else
        {
            if (ans1.first < ans2.first)
            {
                dp[budget][n] = ans1;
            }
            else
            {
                dp[budget][n] = ans2;
            }
        }
    }
    return dp[budget][n];
}

int main()
{

    while (true)
    {
        int budget, n;
        cin >> budget >> n;
        if (budget == 0 && n == 0)
        {
            break;
        }

        int *entry = new int[n];
        int *fun = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> entry[i] >> fun[i];
        }

        pair<int, int> **dp = new pair<int, int> *[budget + 1];
        for (int i = 0; i <= budget; i++)
        {
            dp[i] = new pair<int, int>[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }

        // pair<int, int> res = maxFun(entry, fun, budget, n, dp);
        // cout << res.first << " " << res.second << endl;

        pair<int, int> pair;
        pair = solve_dp(n, budget, entry, fun);
        cout << pair.first << " " << pair.second << endl;
        for (int i = 0; i < budget; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
    }

    return 0;
}
