/* Magic Grid Problem
Send Feedback
You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.
Input format:
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.
Output format:
Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
Constraints:
1 ≤ T ≤ 5
2 ≤ R, C ≤ 500
-10^3 ≤ A[i][j] ≤ 10^3
A[1][1] = A[R][C] = 0
Time Limit: 1 second
Sample Input 1:
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output 1:
2
1
2
 */

#include <bits/stdc++.h>
using namespace std;

int magic_grid(vector<vector<int>> grid, int si, int sj, int row, int col)
{

    if (si == row - 1 && sj == col - 1)
    {
        return 1;
    }

    //* out of bounds
    if (si >= row || sj >= col)
    {
        return INT_MAX;
    }

    //* right call
    int right = magic_grid(grid, si, sj + 1, row, col);
    if (right != INT_MAX)
    {
        right -= grid[si][sj + 1];
    }

    //* down call
    int down = magic_grid(grid, si + 1, sj, row, col);
    if (down != INT_MAX)
    {
        down -= grid[si + 1][sj];
    }

    int current_pos_cost = min(right, down);

    if (current_pos_cost <= 0)
    {
        return 1;
    }
    return current_pos_cost;
}

int magic_grid_memo(vector<vector<int>> grid, int si, int sj, int row, int col, vector<vector<int>> memo)
{

    if (si == row - 1 && sj == col - 1)
    {
        return 1;
    }

    //* out of bounds
    if (si >= row || sj >= col)
    {
        return INT_MAX;
    }
    if (memo[si][sj] != -1)
    {
        return memo[si][sj];
    }

    // right call
    int right = magic_grid(grid, si, sj + 1, row, col);
    if (right != INT_MAX)
    {
        right -= grid[si][sj + 1];
    }

    // down call
    int down = magic_grid(grid, si + 1, sj, row, col);
    if (down != INT_MAX)
    {
        down -= grid[si + 1][sj];
    }

    int current_pos_cost = min(right, down);

    if (current_pos_cost <= 0)
    {
        memo[si][sj] = 1;
        return 1;
    }
    memo[si][sj] = current_pos_cost;
    return current_pos_cost;
}

int solveGrid(int **arr, int m, int n)
{
    int strength = 1;
    int minimum = 0;
    int dp[m][n];
    dp[m - 1][n - 1] = 1;
    for (int i = m - 2; i >= 0; i--)
    {
        dp[i][n - 1] = dp[i + 1][n - 1] - arr[i][n - 1];
    }
    for (int j = n - 2; j >= 0; j--)
    {
        dp[m - 1][j] = dp[m - 1][j + 1] - arr[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - arr[i][j];
            if (dp[i][j] < 1)
            {
                dp[i][j] = 1;
            }
        }
    }

    /*  for (int i = 0; i < m; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout << dp[i][j] << " ";
         }
         cout << endl;
     } */
    // cout << endl;
    // strength = minimum * -1 + 1;
    return dp[0][0];
}

int magic_grid_dp(vector<vector<int>> grid, int row, int col)
{
    int dp[row][col];

    //* how much depth at that position
    //* abs() + 1 (minimum 1 life required)
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {

            if (i == row - 1 && j == col - 1)
            {
                dp[i][j] = 0;
            }

            //* last row
            else if (i == row - 1)
            {
                dp[i][j] = min(0, grid[i][j] + dp[i][j + 1]);
            }

            //* last column
            else if (j == col - 1)
            {
                dp[i][j] = min(0, grid[i][j] + dp[i + 1][j]);
            }
            else
            {
                dp[i][j] = min(0, grid[i][j] + max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return abs(dp[0][0]) + 1;
}
int magic_grid_dp2(vector<vector<int>> grid, int row, int col)
{
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));

    dp[row][col - 1] = 1;
    dp[row - 1][col] = 1;

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            //* at current position how much life we need to further survive
            //* minimum of left and right ans subtract that position's value from
            //* if it less than 0 then put 1 cause atlest we ned 1 life to survive
            int need = min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j];
            dp[i][j] = need <= 0 ? 1 : need;
        }
    }

    return dp[0][0];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        /*   int m, n;
          cin >> m >> n;
          int **arr = new int *[m];

          for (int i = 0; i < m; i++)
          {
              arr[i] = new int[n];
              for (int j = 0; j < n; j++)
              {
                  cin >> arr[i][j];
              }
          } */
        int row, col;
        cin >> row >> col;
        vector<vector<int>> grid;
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < col; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
            temp.clear();
        }
        //* recursive function
        // int ans = magic_grid(grid, 0, 0, row, col);

        //* memoization
        vector<vector<int>> memo(row, vector<int>(col, -1));
        //   int ans = magic_grid_memo(grid, 0, 0, row, col, memo);

        //* DP
        int ans = magic_grid_dp(grid, row, col);

        //   int ans = magic_grid_dp2(grid, row, col);

        cout << ans << endl;
        // cout << solveGrid(arr, m, n) << endl;
    }

    return 0;
}
