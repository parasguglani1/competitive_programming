/* Find power of a number
Send Feedback
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to print the answer.
Note : For this question, you can assume that 0 raised to the power of 0 is 1


Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)
Constraints:
0 <= x <= 8
0 <= n <= 9
Sample Input 1 :
 3 4
Sample Output 1 :
81
Sample Input 2 :
 2 5
Sample Output 2 :
32 */

#include <bits/stdc++.h>
using namespace std;
int find_pow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * find_pow(x, n - 1);
    }
}
int main()
{
    int x, n;
    cin >> x >> n;
    // int ans =     find_pow(x, n);
    // for(int i=0;i<n;i++)
    // {
    //     ans=ans*x;
    // }
    int ans = pow(x, n);
    cout << ans;
    return 0;
}

