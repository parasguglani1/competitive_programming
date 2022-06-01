#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//? approch 1
/* Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array. */
int maxProductSubarray(int arr[], int n)
{
    // Initialize overall max product
    int max_so_far = 0;
    // max positive product
    // ending at the current position
    int max_ending_here = 1, min_ending_here = 1;
    // min negative product ending
    // at the current position
    int flag = 0;
    /* Traverse through the array.
   Following values are
   maintained after the i'th iteration:
   max_ending_here is always 1 or
   some positive product ending with arr[i]
   min_ending_here is always 1 or
   some negative product ending with arr[i] */

   
    for (int i = 0; i < n; i++)
    {
        /* If this element is positive, update
        max_ending_here. Update min_ending_here only if
        min_ending_here is negative */
        if (arr[i] > 0)
        {                                                       //* positive
            max_ending_here = max_ending_here * arr[i];         //* always be positive
            min_ending_here = min(min_ending_here * arr[i], 1); //* no more than 1
            flag = 1;
        }
        else if (arr[i] == 0)
        /* If this element is 0, then the maximum product
       cannot end here, make both max_ending_here and
       min_ending_here 0
       Assumption: Output is alway greater than or equal
                   to 1. */
        { //* anything multiply with zero == zero
            max_ending_here = 1;
            min_ending_here = 1;
        }
        else
        {   /* If element is negative. This is tricky
          max_ending_here can either be 1 or positive.
          min_ending_here can either be 1 or negative.
          next max_ending_here will always be prev.
          min_ending_here * arr[i] ,next min_ending_here
          will be 1 if prev max_ending_here is 1, otherwise
          next min_ending_here will be prev max_ending_here *
          arr[i] */
            //* negative value
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1); //* -12 * -5 == 60 //* it would be greater than 0
            min_ending_here = temp * arr[i];                    //* 24 * -5 == -120
        }
        max_so_far = max(max_ending_here, max_so_far);
    }
    if (flag == 0 && max_so_far == 0)
        return 0;
    /* if all the array elements are negative */
    if (max_so_far == 1)
    {
        max_so_far = arr[0];
        for (int i = 1; i < n; i++)
            max_so_far = max(max_so_far, arr[i]);
    }

    return max_so_far;
}

//? approch 2
int maxSubarrayProduct(int arr[], int n)
{
    // max positive product
    // ending at the current position
    int max_ending_here = arr[0];

    // min negative product ending
    // at the current position
    int min_ending_here = arr[0];

    // Initialize overall max product
    int max_so_far = arr[0];
    /* Traverse through the array.
    the maximum product subarray ending at an index
    will be the maximum of the element itself,
    the product of element and max product ending previously
    and the min product ending previously. */
    for (int i = 1; i < n; i++)
    {
        int temp = max({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        min_ending_here = min({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        max_ending_here = temp;
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main()
{
    // int arr[] = {-2, -3, 4, 5, 6, 0, 50};
    // int size = sizeof(arr)/sizeof(arr[0]);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << maxProductSubarray(arr, n) << endl;
    }
    return 0;
}