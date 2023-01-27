// max subarray sum return

#include <bits/stdc++.h>
using namespace std;

int kadane(int a[], int n, int s[])
{
    s[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] + s[i - 1] > a[i])
        {
            s[i] = a[i] + s[i - 1];
        }
        else
        {
            s[i] = a[i];
        }
    }
    int maxnum = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] > maxnum)
        {
            maxnum = s[i];
        }
    }
    return maxnum;
}

int kadane(int a[], int n)
{
    int s[n];
    return kadane(a, n, s);
}
int kadane2(int a[], int n)
{
    int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
    for (int i = 0; i < n; i++)
    {
        curMax = max(a[i], curMax + a[i]); // update the current max subarray sum
        maxSum = max(maxSum, curMax);      // update the overall max subarray sum
    }

    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << kadane2(a, n);
    return 0;
}
