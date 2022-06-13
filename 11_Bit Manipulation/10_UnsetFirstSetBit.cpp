/* Turn off 1st set bit
Send Feedback
You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N 
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12 
Sample Output 2 :
8 */
#include <bits/stdc++.h>
using namespace std;
int unSetI(int n, int i)
{
    return (n & ~(1 << i));
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
    m = unSetI(n, i);
    return m;

// 2nd method
    // return n ^ (n & (-n));
}
//2nd method
int turnOffFirstSetBit(int n)
{

    return n & (n - 1);
}

int main()
{
    int n;
    cin >> n;
    int m = turnOffFirstSetBit(n);
    cout << m << endl;

    return 0;
}