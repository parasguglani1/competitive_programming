#include <bits/stdc++.h>
using namespace std;

int getMaxsumN6(int **mat, int row, int col)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = i; k < row; k++)
            {
                for (int l = j; l < col; l++)
                {
                    int sum = 0;
                    for (int p = i; p <= k; p++)
                    {
                        for (int q = j; q <= l; q++)
                        {
                            sum += mat[p][q];
                        }
                    }
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }
    return maxSum;
}

int max_sumN4(int n, int m, int **mat)
{
    // find sum from each index to the end
    int** storage = new int *[n];
    for (int i = 0; i < n; i++)
    {
        storage[i] = new int[m]{};
    }
    // O(n^4)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // find sum for each ~ [i][j] till end ~ [n-1][m-1]
            for (int r = i; r < n; r++)
            {
                for (int c = j; c < m; c++)
                {
                    storage[i][j] += mat[r][c];
                }
            }
        }
    }
    int overall_max = INT_MIN;
    // select one start and 1 end

    // select one start and 1 end
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // find sum from that [i][j] till [r][c]
            for (int r = i; r < n; r++)
            {
                for (int c = j; c < m; c++)
                {
                    int curr_sum = 0;
                    curr_sum += storage[i][j];

                    if (r < n - 1)
                    {
                        curr_sum -= storage[r + 1][j];
                    }

                    if (c < m - 1)
                    {
                        curr_sum -= storage[i][c + 1];
                    }

                    if (r < n - 1 && c < m - 1)
                    {
                        curr_sum += storage[r + 1][c + 1];
                    }

                    if (curr_sum > overall_max)
                    {
                        overall_max = curr_sum;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete storage[i];
    }
    delete storage;
    return overall_max;
}

int max_sumN3(int n, int m, int **mat)
{
    // select start and end col
    // int *sum_storage = new int[n]{};

    int overall_max = INT_MIN;

    for (int s = 0; s < m; s++)
    {

        int *sum_storage = new int[n]{};
        for (int e = s; e < m; e++)
        {

            // find sum of all rows in between these start and end columns
            // using previously stored sum to find next sum
            for (int i = 0; i < n; i++)
            {
                sum_storage[i] += mat[i][e];
            }

            // now i have a storage of sums of rows between start and end columns
            // use kadane's algo to find the max sum consecutive subarray and their indices in this sums of rows

            int max_sum_kadane = INT_MIN;
            int curr_sum_kadane = 0;
            for (int i = 0; i < n; i++)
            {
                curr_sum_kadane += sum_storage[i];
                max_sum_kadane = max(max_sum_kadane, curr_sum_kadane);
                if (curr_sum_kadane < 0)
                {
                    curr_sum_kadane = 0;
                }
            }
            overall_max = max(overall_max, max_sum_kadane);
        }
    }

    return overall_max;
}
/*
// O(n^3) solution with kadane function
int kadane(int *arr, int n)
{
    int curr_sum = 0, max_so_far = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum > max_so_far)
        {
            max_so_far = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_so_far;
}

int maxSumRectangle(int **arr, int n, int m)
{
    int sum = INT_MIN;
    // starting column (i)
    for (int i = 0; i < m; i++)
    {
        int *temp = new int[n]();
        // loop from starting column to last column
        for (int j = i; j < m; j++)
        {
            // loop from 0th row to last row
            for (int k = 0; k < n; k++)
            {
                temp[k] += arr[k][j];
            }
            sum = max(sum, kadane(temp, n));
        }
    }
    return sum;
}
 */

int main()
{
    int n, m;
    cin >> n >> m;
    int kadane_sum;
    // int mat[n + 1][m];
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    // cout<<getMaxsumN6(mat,n,m);
    // O(n^4)
    // cout<<max_sumN4(n,m,mat)<<endl;

    // O(n^3)
    cout << max_sumN3(n, m, mat) << endl;
    return 0;
}
