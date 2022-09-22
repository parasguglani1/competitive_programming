#include <bits/stdc++.h>
using namespace std;
//minimum cost to reach m,n; diagonal movement allowed
int min_cost(int **arr, int si, int sj, int ei, int ej)
{
    if (si == ei && sj == ej)
    {
        return arr[si][sj];
    }
    if (si > ei || sj > ej)
    {
        return INT_MAX;
    }
    int case1 = min_cost(arr, si + 1, sj, ei, ej);
    int case2 = min_cost(arr, si, sj + 1, ei, ej);
    int case3 = min_cost(arr, si + 1, sj + 1, ei, ej);

    return( arr[si][sj] + min(case1, min(case2, case3)));
}
int min_cost_memo(int **input, int si, int sj, int ei, int ej, vector<vector<int>> memo)
{
    if (si == ei && sj == ej)
    {
        return input[ei][ej];
    }
    //* when out of bound breached
    if (si > ei || sj > ej)
    {
        return INT_MAX;
    }
    // check if path already explored

    if (memo[si][sj] > -1)
    {
        return memo[si][sj];
    }

    int option1 = min_cost(input, si + 1, sj, ei, ej);
    int option2 = min_cost(input, si, sj + 1, ei, ej);
    int option3 = min_cost(input, si + 1, sj + 1, ei, ej);

    memo[si][sj] = input[si][sj] + min(option1, min(option2, option3));
    //* current cost + previous minimum path cost
    return input[si][sj] + min(option1, min(option2, option3));
}
int min_cost_iter(int **arr, int m, int n)
{
    int dp[m][n];
    dp[m - 1][n - 1] = arr[m - 1][n - 1];
    //filling last row
    for (int i = n - 2; i >= 0; i--)
    {
        dp[m - 1][i] = dp[m - 1][i + 1]+arr[m - 1][i];
    }
    // filling last collumn

    for (int j = m - 2; j >= 0; j--)
    {
        dp[j][n - 1] = dp[j + 1][n - 1] + arr[j][n - 1];
    }
    // fill rest matrix
    //* current cost + minimum of all three cost

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = arr[i][j] + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
        }
    }


    return dp[0][0];
}
int main()
{

    int **input = new int *[3];
    input[0] = new int[3];
    input[1] = new int[3];
    input[2] = new int[3];
    input[0][0] = 4;
    input[0][1] = 3;
    input[0][2] = 2;
    input[1][0] = 1;
    input[1][1] = 8;
    input[1][2] = 3;
    input[2][0] = 1;
    input[2][1] = 1;
    input[2][2] = 8;


    vector<vector<int>> memo(3, vector<int>(3, -1));
    cout << min_cost_memo(input, 0,0,2,2, memo) << endl;
    // cout << min_cost(input, 0, 0, 2, 2) << endl;
    cout << min_cost_iter(input, 3, 3) << endl;
    delete[] input[0];
    delete[] input[1];
    delete[] input[2];
    delete[] input;
    return 0;
}
