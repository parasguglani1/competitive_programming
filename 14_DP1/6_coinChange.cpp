/* Coin Change Problem
Send Feedback
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903

 */

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> out;

int coin(int *a, int len, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (len == 0)
        return 0;
    if (out[n][len] > -1)
        return out[n][len];
    // Fill rest of the table entries
    // in bottom up manner
    // starting element of den included
    int first = coin(a, len, n - a[0]);
    // starting element of den not included
    int second = coin(a + 1, len - 1, n);
    out[n][len] = first + second;
    return first + second;
}

int countWaysToMakeChange(int a[], int len, int n)
{
    out = vector<vector<int>>(n + 1, vector<int>(len + 1, -1));
    return coin(a, len, n);
}

int main()
{

    /* int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int v;
    cin >> v;
    int *dp = new int[v + 1];
    dp[0] = 1;
    for (int i = 1; i <= v; i++)
    {
        dp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j <= v; j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }
    cout << dp[v] << endl; */

    int n, v;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> v;
    cout << countWaysToMakeChange(a, n, v);
    delete[] a;

    return 0;
}
