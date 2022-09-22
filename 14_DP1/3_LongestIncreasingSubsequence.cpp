#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>

// We can see that there are many subproblems in the above recursive solution which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation.
int lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

// If we closely observe the problem then we can convert this problem to longest Common Subsequence Problem. Firstly we will create another array of unique elements of original array and sort it. Now the longest increasing subsequence of our array must be present as a subsequence in our sorted array. That’s why our problem is now reduced to finding the common subsequence between the two arrays.

int lis2(int arr[], int n)
{
    vector<int> b;
    set<int> s;

    // setting iterator for set
    set<int>::iterator it;

    // storing unique elements
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    // creating sorted vector
    for (it = s.begin(); it != s.end(); it++)
    {
        b.push_back(*it);
    }
    int m = b.size(), i, j;
    int dp[m + 1][n + 1];

    // storing -1 in dp multidimensional array
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    // Finding Longest common Subsequence of the two
    // arrays
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[j - 1] == b[i - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// memoization dp
int f(int idx, int prev_idx, int n, int a[],
      vector<vector<int>> &dp)
{
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][prev_idx + 1] != -1)
    {
        return dp[idx][prev_idx + 1];
    }

    int notTake = 0 + f(idx + 1, prev_idx, n, a, dp);
    int take = INT_MIN;
    if (prev_idx == -1 || a[idx] > a[prev_idx])
    {
        take = 1 + f(idx + 1, idx, n, a, dp);
    }

    return dp[idx][prev_idx + 1] = max(take, notTake);
}
// Function to find length of longest increasing
// subsequence.
int longestSubsequence(int n, int a[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(0, -1, n, a, dp);
}

// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}
// nlogn
int LongestIncreasingSubsequenceLength(std::vector<int> &v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    return length;
}

int main()
{
    std::vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
    std::cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasingSubsequenceLength(v) << '\n';
    return 0;
}
