#include <bits/stdc++.h>
using namespace std;

int get_first_index(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }

    else if (arr[0] == x)
    {
        return 0;
    }
    int index = get_first_index(arr + 1, n - 1, x);

    if (index == -1)
    {
        return -1;
    }
    else
    {
        return index + 1; //because recursive call has started from 1 and not 0
    }
  ;
}

int main()
{
    int n = 5, x = 4;
    int arr[n] = {3, 2, 3, 8, 3};
    int index = -1;

    index = get_first_index(arr, n, x);
    cout << index;

    return 0;
}