#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getsubsetRecursive(int *arr, int n, int x)
{
    if (n == 0)
    {
        if (x == 0)
        {
            vector<int> v;
            vector<vector<int>> v1;
            v1.push_back(v);
            return v1;
        }
        else
        {
            vector<vector<int>> v1;
            return v1;
        }
    }
    vector<vector<int>> v1 = getsubsetRecursive(arr + 1, n - 1, x);
    vector<vector<int>> v2 = getsubsetRecursive(arr + 1, n - 1, x - arr[0]);
    for (int i = 0; i < v2.size(); i++)
    {
        v2[i].push_back(arr[0]);
    }
    for (int i = 0; i < v2.size(); i++)
    {
        v1.push_back(v2[i]);
    }
    return v1;
}


int getcount(int *arr, int n, int x)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[x + 1];
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= x; i++)
    {
        dp[n][i] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= x; j++)
        {
            int c1 = 0;
            if (j - arr[i] >= 0)
            {
                c1 = dp[i + 1][j - arr[i]];
            }
            int c2 = dp[i + 1][j];
            dp[i][j] = c1 + c2;
        }
    }
    return dp[0][x];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    vector<vector<int>> subsets;
    subsets = getsubsetRecursive(arr, n, x);

    for (int i = 0; i < subsets.size(); i++)
    {
        for (int j = 0; j < subsets[i].size(); j++)
        {
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
