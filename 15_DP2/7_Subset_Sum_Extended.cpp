
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> num, int n, int s)
{
    vector<vector<int>> dp(2, vector<int>(s + 1, 0));
    for (int i = 0; i < s + 1; i++)
    {
        dp[0][i] == false;
    }
    dp[0][0] = true;
    dp[1][0] = true;

    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            //* flag == 0 => 1, flag == 1 => 1
            dp[flag][j] = dp[flag ^ 1][j];

            if (j >= num[i - 1])
            {
                dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j - num[i - 1]];
            }
        }
        flag = flag ^ 1;
    }
    return dp[flag ^ 1][s];
}

int main()
{
    int n, sum;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
    }
    cin >> sum;
    if (check(num, n, sum))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
