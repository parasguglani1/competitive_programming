#include <bits/stdc++.h>
using namespace std;

int get_index(int arr[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }

    else if (arr[0] == x)
    {
        return true;
    }
    int index = get_index(arr + 1, n - 1, x);

    return index;
}

int main()
{
    int n = 5, x = 7;
    int arr[n] = {1, 2, 3, 8, 5};
    int index = -1;

    index = get_index(arr, n, x);
    cout << index;

    return 0;
}