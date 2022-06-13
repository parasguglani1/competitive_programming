int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x - 1);
        count++;
    }
    return count;
}

// Find log base 2 of 32 bit integer

    int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}
int lastSetBit(int n)
{
    return log2(n & -n) + 1;
}

// Upper case English alphabet to lower case

    // ch |= ' ';

// Lower case English alphabet to upper case

//     ch &= '_’ ;

// Direct XOR of all numbers from 1 to n
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

//   Number of leading zeroes: __builtin_clz(x)
//   Number of trailing zeroes : __builtin_ctz(x)
//   Number of 1-bits: __builtin_popcount(x)

// Conversion into Binary code //
#include <iostream>
    using namespace std;

int main()
{
    auto number = 0b011;
    cout << number;
    return 0;
}

// C++ implementation to check if a number
// has bits in alternate pattern
#include <bits/stdc++.h>
// https://www.geeksforgeeks.org/check-number-bits-alternate-pattern-set-2-o1-approach/
using namespace std;

// function to check if all the bits are set or not
// in the binary representation of 'n'
bool allBitsAreSet(unsigned int n)
{
    // if true, then all bits are set
    if (((n + 1) & n) == 0)
        return true;
    // else all bits are not set
    return false;
}

// function to check if a number has bits in alternate
// pattern
bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);
    // to check if all bits are set in 'num'
    return allBitsAreSet(num);
}
void odd_even(int n)
{
    if (n & 1)
    {
        cout << "odd" << endl;
    }
    else
    {
        cout << "even" << endl;
    }
}

int findOddFrequencyElement(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
