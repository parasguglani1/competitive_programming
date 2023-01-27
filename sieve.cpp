#include <bits/stdc++.h>
using namespace std;
#define N 1000000
bool isPrime[N] = {0};
vector<int> primes;
int sieve(int n)
{
    int count = 0;
    for (int i = 2; i < n + 1; i++)
    {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        if (isPrime[i] == true)
        {
            count++;
            primes.push_back(i);
        }
    }

    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << sieve(n) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << isPrime[i] << " ";
    }

    return 0;
}
