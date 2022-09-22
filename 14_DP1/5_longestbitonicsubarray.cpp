/*
You are given an array of positive integers as input. Write a code to return the length of the largest such sub-array in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a sub-array is known as bitonic sub-array. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic sub-array need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array
Output Format:
Length of Largest Bitonic Sub-Array
Input Constraints:
1<= N <= 10^5
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic sub-array is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include <bits/stdc++.h>

using namespace std;

int longestBitonicSubarray(int *arr, int n)
{
   int i, j;
   // linearly increasing and decreasing sequence
   /* Allocate memory for LIS[] and initialize LIS values as 1 for
      all indexes */
   int *lis = new int[n];
   for (i = 0; i < n; i++)
      lis[i] = 1;

   // all numbers having value less than current number in left

   /* Compute LIS values from left to right */
   for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;

   /* Allocate memory for lds and initialize LDS values for
      all indexes */
   int *lds = new int[n];
   for (i = 0; i < n; i++)
      lds[i] = 1;

//all numbers having value less than current number in right
   /* Compute LDS values from right to left */
   for (i = n - 2; i >= 0; i--)
      for (j = n - 1; j > i; j--)
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;

   /* Return the maximum value of lis[i] + lds[i] - 1*/
   int max = lis[0] + lds[0] - 1;
   for (i = 1; i < n; i++)
      if (lis[i] + lds[i] - 1 > max)
         max = lis[i] + lds[i] - 1;
   cout << "lis" << endl;

   for (int i = 1; i < n; i++)
   {
      cout << lis[i] << " ";
   }
   cout << endl
        << "lds" << endl;

   for (int j = 0; j < n - 1; j++)
   {
      cout << lds[j] << " ";
   }
   cout << endl;
   return max;
}

/* int* lis(int* arr, int n){
    int* out = new int[n];
    out[0] = 1;
    for(int i=1; i<n; i++){
        int curr_max = 0;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                curr_max = max(curr_max , out[j]);
            }
            out[i] = curr_max+1;
        }
    }
    return out;
}Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”


int* lis_reverse(int* arr, int n){
    int* out = new int[n];
    out[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        int curr_max = 0;
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                curr_max = max(curr_max , out[j]);
            }
            out[i] = curr_max+1;
        }
    }
    return out;
}

int longestBitonicSubarray(int *input, int n) {
   int* lis_front = lis(input, n);
    int* lis_back = lis_reverse(input, n);
    int maximum = 2;
    for(int i=0; i<n; i++){
        maximum = max(maximum, lis_front[i] + lis_back[i] - 1);
    }
    return maximum;
} */
int main(int argc, char **argv)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, input[100000];
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> input[i];
   }
   cout << longestBitonicSubarray(input, n);
   return 0;
}
