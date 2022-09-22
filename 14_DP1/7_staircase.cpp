/*

//for 3 choices
StairCase Problem
Send Feedback
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274
 */

#include <bits/stdc++.h>
using namespace std;
int sol[1000];

int getWays(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    if (sol[n] == -1)
    {
        int ans = getWays(n - 1) + getWays(n - 2) + getWays(n - 3);
        return sol[n] = ans;
    }

    return sol[n];
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        memset(sol, -1, sizeof(sol));
        sol[1] = 0;
        sol[2] = 1;
        int n;
        cin >> n;
        cout << getWays(n) << endl;
    }

    return 0;
}
