/* Target Marbles

At CodingNinjas, we love to play with marbles. We have many marble games, but the most popular one is “Target Marbles”. Now, our marbles are unique. Each marble has a number on it.

In Target Marbles, the player is given a number in the starting and this number is called target. The player is also given N number of marbles to play with. Now, player has to arrange the marbles in a specific way such that sum of the values of at least one of the continuous subset of the arrangement is equal to given target.
Now, NinjaCoder came to play this game and made an arrangement of marbles. The judges of the game need your help. You have to determine if NinjaCoder has won it or not.
Input Format :
First line contains number of marbles(N) and target (target_number) that was assigned to NinjaCoder. Second line contains N space separated integers, which represent arrangement of the marbles and value written on that particular marble.
Constraints:
1<= N <=100
1<=target_number<=10000
Value on the marbles lies in the range [0, 1000].
Output Format :
You have to print “true”, if the NinjaCoder wins with the given arrangement and you have to print the values of the continuous subsets. If there are more that one continuous subsets, then you have to print the values of first continuous subset. If the Ninjas coder is unable to win, you just have to print “false”.
Sample Input 1 :
10 10
9 1 2 3 4 5 5 16 17 19
Sample Output 1 :
true
9 1
Explanation:
Here, if the NinjaCoder arranges the given 10 marbles in this arrangement, then he/she will win the game. Now, there are many continuous subsets of marbles that will win the game such as (9,1) or (1, 2, 3, 4). Out of these winning combinations, you have to print the first one which is (9,1).
Sample Input 2 :
10 10
19 11 12 131 14 15 5 16 17 19
Sample Output 2:
false */

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
	int n, t;
	cin >> n >> t;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{

		int sum = 0;
		int number = i;
		vector<int> v;

		while ((sum != t) && (number < n))
		{
			sum += arr[number];
			v.push_back(arr[number]);
			number += 1;
		}
		if (sum == t)
		{
			cout << "true" << endl;
			for (int j = 0; j < v.size(); j++)
			{
				cout << v[j] << " ";
			}
			return;
		}
	}
	cout << "false";
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

	w(t)
	{
		pgsolve();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef __GNUC__
	cerr << "\n Time: " << duration.count() / 1000 << " ms" << endl;
#endif
	return 0;
}