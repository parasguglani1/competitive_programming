// You are given an array A with size N (indexed from 0) and an integer K. Let's define another array B with size N · K as the array that's formed by concatenating K copies of array A.
// For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.
// You have to find the maximum subarray sum of the array B. Fomally, you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, where 0 ≤ i ≤ j < N · K.

// Input:
// 2
// 2 3
// 1 2
// 3 2
// 1 -2 1

// Output:
// 9
// 2

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
		
//kadane
	ll kadane(ll arr[], ll n)
	{
	// 	Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

	// A subarray is a contiguous part of an array.


		ll curr_sum = 0;
		ll max_so_far = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			curr_sum = curr_sum + arr[i];
			if (max_so_far < curr_sum)
			{
				max_so_far = curr_sum;
			}

			if (curr_sum < 0)
			{
				curr_sum = 0;
			}
		}
		return max_so_far;
	}
ll maxSubarraySum(ll *arr, ll n, ll k)
{
	ll kadanes_sum = kadane(arr, n);
	if (k == 1)
	{
		return kadanes_sum;
	}

	ll curr_prefix_sum = 0, curr_suffix_sum = 0;
	ll max_prefix_sum = INT_MIN, max_suffix_sum = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		curr_prefix_sum = curr_prefix_sum + arr[i];
		max_prefix_sum = max(max_prefix_sum, curr_prefix_sum);
	}
	ll totalSum = curr_prefix_sum;
	for (int i = n - 1; i >= 0; --i)
	{
		curr_suffix_sum += arr[i];
		max_suffix_sum = max(max_suffix_sum, curr_suffix_sum);
	}

	ll ans;
	if (totalSum < 0)
	{
		ans = max(max_suffix_sum + max_prefix_sum, kadanes_sum);
	}
	else
	{
		ans = max(max_suffix_sum + max_prefix_sum + totalSum * (k - 2), kadanes_sum);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll arr[n];
		for (int i = 0; i < n; ++i)
		{
			std::cin >> arr[i];
		}
		cout << maxSubarraySum(arr, n, k) << '\n';
	}

	return 0;
}
