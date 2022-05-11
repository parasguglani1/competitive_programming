#include <bits/stdc++.h>
using namespace std;

int sum_of_array(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    int sum = sum_of_array(arr + 1, n - 1) + arr[0];

    return sum;
}

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    int sum = 0;

    sum = sum_of_array(arr, n);
    cout << sum;

    return 0;
}