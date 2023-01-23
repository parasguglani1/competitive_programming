/* Subset Sum - Problem
Send Feedback
You are given a set of N integers. You have to return true if there exists a subset that sum up to K, otherwise return false.
Input Format
The first line of the test case contains an integer 'N' representing the total elements in the set.

The second line of the input contains N integers separated by a single space.

The third line of the input contains a single integer, denoting the value of K.
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Constraints :
1 <= N <= 10^6
1 <= a[i] <= 10^3, where a[i] denotes an element of the set
1 <= K <= 10^3

Time Limit: 1 sec
Sample Input 1 :
4
4 3 5 2
13
Sample Output 1 :
No
Sample Input 2 :
5
4 2 5 6 7
14
Sample Output 2 :
Yes */
#include <bits/stdc++.h>
using namespace std;
// to reduce storage we can use only 2 rows dp array
// this is memory optimization just like in knapsack
// XOR can be used to toggle

bool check(vector<int> num, int n, int s)
{
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    // check possibility

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                //* not take current number
                dp[i][j] = dp[i - 1][j];
                if (j >= num[i - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - num[i - 1]];
                }
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][s];
}

bool checker(int *arr, int n, int k, int **dp)
{
    if (k == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (dp[n][k] >= 0)
    {
        return dp[n][k];
    }
    int ans = 0;
    if (arr[0] <= k)
    {
        bool option1 = checker(arr + 1, n - 1, k, dp);
        bool option2 = checker(arr + 1, n - 1, k - arr[0], dp);
        if (option1 || option2)
        {
            ans = 1;
        }
    }
    else
    {
        ans = checker(arr + 1, n - 1, k, dp);
    }
    dp[n][k] = ans;
    return dp[n][k];
}

int main()
{

    int n, sum;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // cin >> sum;
    /* bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    } */
    /*    if (dp[n][sum])
       {
           cout << "Yes";
       }
       else
       {
           cout << "No";
       } */
    vector<int> num;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     num.push_back(x);
    // }
    cin >> sum;

    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[sum + 1];
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = checker(a, n, sum, dp);
    // int ans2 = check(num, n, sum);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // cout<<dp[3][8]<<" "<<dp[2][6]<<" "<<dp[4][11];
     if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
