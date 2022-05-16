#include <bits/stdc++.h>
using namespace std;

int lastIndex(int arr[], int size, int x)
{

    if (size == 0)
        return -1;

    int smallerAns = lastIndex(arr + 1, size - 1, x);

    if (arr[0] == x && smallerAns == -1)
        return 0; // hit only one time when first time number found (reverse order)

    if (smallerAns == -1)
    { // still number not found
        return -1;
    }
    else
    {
        return smallerAns + 1;
    }
}

int main()
{
    int n = 5, x = 4;
    int arr[n] = {3, 2, 3, 8, 3};
    int index = -1;

    index = lastIndex(arr, n, x);
    cout << index;

    return 0;
}