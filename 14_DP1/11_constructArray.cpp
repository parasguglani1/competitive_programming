#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long count_array(int n, int k, int x)
{
    //* if n == 1 then
    // first position need to be fild by 1
    long oneCount = 1;
    long nonOneCount = 0;

    for (int i = 1; i < n; i++)
    {
        long preOneCount = oneCount;
        //* previous position filld with nonOne [x,x,1,nonOneCount * (k-1)]
        oneCount = nonOneCount * (k - 1)%mod;
        //* previous position filld with 1 or any k number [x,x, 1 / k, oneCount + nonOneCount* (k-1)]
        nonOneCount = (preOneCount + ((nonOneCount * (k - 2) % mod))) % mod;
    }

    //* first position is 1 and also last  position(x) == 1 then return
    if (x == 1)
    {
        return oneCount;
    }

    //* last possition need to fild with nonOne
    else
    {
        return nonOneCount;
    }
}

// method2 -using some storage
// Complete the countArray function below.
long countArray(int n, int k, int x)
{
    // Return the number of ways to fill in the array.

    long m = 1000000007;

    long a[n]; // to store no of possibilities of length i ending at x
    long b[n]; // to store no of possibilities of length i not ending at x

    if (x != 1)
    {
        a[0] = 0;
        b[0] = 1;
    }
    else
    {
        a[0] = 1;
        b[0] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        a[i] = b[i - 1] % m;
        b[i] = ((a[i - 1] * (k - 1)) % m + (b[i - 1] * (k - 2)) % m) % m;
    }

    return a[n - 1];
}

// method3 -using prev vars instead of storage, similar to last but just using 3 vars
// Complete the countArray function below.
long countArray(int n, int k, int x)
{
    // Return the number of ways to fill in the array.

    long a, a_prev, b, b_prev;

    long m = 1000000007;

    a_prev = x == 1 ? 1 : 0;
    b_prev = x == 1 ? 0 : 1;

    for (int i = 1; i < n; i++)
    {
        a = b_prev % m;
        b = ((a_prev * (k - 1)) % m + (b_prev * (k - 2)) % m) % m;
        a_prev = a % m;
        b_prev = b % m;
    }
    return a;
}
int main()
{
    int n, k, x;
    cin >> n >> k >> x;

    //* 1st element must be 1
    //* last element must be x
    //* all elements must be between 1 to k (inclusive);
    cout << count_array(n, k, x) << endl;

    return 0;
}
