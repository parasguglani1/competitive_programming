/* Even and Odd Indexes

Given an array of integers, print two integer values:
First, the sum of all numbers which are even as well as whose index are even.
Second, the sum of all numbers which are odd as well as whose index are odd.
Print the two integers space separated. (Arrays is 0-indexed)
Input:
Given an integer denoting the size of array.
Next line will have a line containing ‘n’ space separated integers.
Constraints:
1<=n<=10^5
1 <= Ai <= 10^6
Output:
Two space separated integers denoting even and odd sums respectively.
Sample Input:
5
2 3 5 1 4
Sample Output:
6 4 */

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define ff first
#define ss second
#define int long long
using ll = long long;
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define PI 3.1415926535897932384626
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
	int x;    \
	cin >> x; \
	while (x--)
#define sortall(x) sort(all(x))
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, k, n) for (int i = k; i < n; ++i)
#define REPR(i, k, n) for (int i = k; i > n; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
void pgsolve()
{
	int n;
	cin >> n;
	int a[n];
	int oddsum = 0, evensum = 0;
	rep(i, n)
	{
		cin >> a[i];
		if (i % 2 == 0&& a[i] % 2 == 0)
			evensum += a[i];
		else if (i % 2 != 0&& a[i] % 2 != 0)
			oddsum += a[i];

	}

	cout<<oddsum<<" "<<evensum<<endl;

}

int32_t main()

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	auto start1 = high_resolution_clock::now();

#ifdef __GNUC__
	freopen("error.txt", "w", stderr);
#endif


		pgsolve();

	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef __GNUC__
	cerr << "\n Time: " << duration.count() / 1000 << " ms" << endl;
#endif
	return 0;
}
