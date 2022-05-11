/* Sum Array

Given a 2-d square matrix of order ‘n’, find the sum of elements of both diagonals and all boundaries elements. Boundary elements refer to the elements present on all the four boundaries of matrix.
Input:
First line will have a single integer ‘n’ denoting the order of matrix.
Next ‘n’ lines will have ‘n’ space separated integers each denoting the elements of matrix.
Constraints:
1<=n<=100
Output:
Print a single integer denoting the sum.
Sample input:
3
1 2 3
4 5 6
7 8 9
Sample Output:
45 */


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
	int i, j, n, m;
	cin >> n ;
	int a[n][n];
	rep(i, n)
	{
		rep(j, n)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	rep(i, n)
	{
		ans += a[0][i];
		ans += a[n - 1][i];
	}
	
	REP(i,1, n-1)
	{
		ans += a[i][0];
		ans += a[i][n - 1];
	}

	for(int i=1, j=1; i<n-1&&j<n-1; i++, j++)
	{
		ans += a[i][j];
	}
	for (int i = n - 2, j = 1; i >= 1 && j <= n - 2; i--, j++)
	{
		if (i == j)
		{
			continue;
		}
		ans += a[i][j];
	}

	cout << ans;
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