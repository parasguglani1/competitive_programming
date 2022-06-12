/* Find first set bit
Send Feedback
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
Input Format :
Integer N
Output Format :
Integer M
Sample Input 1 :
7
Sample Output 1 :
1
Sample Input 2 :
12
Sample Output 2 :
4 */
#include <bits/stdc++.h>
using namespace std;
int setI(int n, int i)
{
    return (n | (1 << i));
}

int firstSetBit(int n)
{
    int i = 0;
    while (!(n & (1 << i)))
    {
        i++;
    }
    // cout << " i is " << i << endl;
    int m = 0;
    m = setI(m, i);
    return m;
}

int main()
{
    int n;
    cin >> n;
    int m = firstSetBit(n);
    cout << m << endl;

    return 0;
}