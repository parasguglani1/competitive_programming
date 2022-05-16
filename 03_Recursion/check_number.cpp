#include <bits/stdc++.h>
using namespace std;

bool is_present(int arr[], int n,int x)
{
    if (n == 0)
    {
        return false;
    }

else if (arr[0]==x)
{
    return true;
}
    bool found = is_present(arr + 1, n - 1,x);
    
    return found;
    
}

int main()
{
    int n = 5,x=7;
    int arr[n] = {1, 2, 3, 8, 5};
    bool found = false;

    found = is_present(arr, n,x);
    cout << found;

    return 0;
}