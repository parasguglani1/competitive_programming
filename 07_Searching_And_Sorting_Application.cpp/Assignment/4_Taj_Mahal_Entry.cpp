/* Taj Mahal Entry
Send Feedback
Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal. He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. Find the window number at which he will get the ticket.
Input Format:
First line contains a single integer ‘n’ denoting the no. of windows.
Next line contains ‘n’ space separated integers denoting the no. of people already standing in front of the ith window. (1 <= i <= n)
Output Format:
Print a single integer denoting the window number that Aahad will get ticket from.
Constraints:
1 <= n <= 10^5
1 <= Ai <= 10^9
Sample Input:
4
2 3 2 0
Sample Output:
3
Explanation:
Aahad at Window 1: [2, 3, 2, 0]
Aahad at Window 2: [1, 2, 1, 0]
Aahad at Window 3: [0, 1, 0, 0]
So, when Aahad is at window 3, he got zero people before him. Hence, he will get the ticket at window 3. */

#include <bits/stdc++.h>
using namespace std;
// binary search
int TajMahal(vector<int> &a, int n)
{
    vector<int> t_value(n);
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 1000000000, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if ((i + mid * n) >= a[i])
            {
                t_value[i] = (i + mid * n);
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
    }
    int min = 0;
    for (int i = 1; i < n; i++)
        if (t_value[min] > t_value[i])
            min = i;
    return min + 1;
}
//for in place by calculating cycles 

int go(vector<int> window, int min_index)
{
    int n = window.size();
    int pos = window.at(min_index) % n;
    int min_value = window.at(min_index);
    cout << min_index << '\n';
    cout << pos << '\n';

    if (pos == min_index)
    {
        return min_index;
    }

    int cycles = min_value / n;

    for (int i = pos; i < n + pos; ++i)
    {
        window.at(i % n) = window.at(i % n) - abs(i - pos) - cycles * n - min_value;
        if (window.at(i % n) <= 0)
        {
            return i % n;
        }
    }

    return 0;
}

/*
it is working on a maths formula
i + t*n >= a[i];
it is the base and core logic for solving this problem
note that we can also solve this question by the complexity on O(n)
try to make logic as follows
for(int i=0; i<n; i++){
t = (a[i]-i)/n;
if a[i]-i == 0
then there will be no change in t
other wise t = t+1
since we want the rround number
and intiger division will give 5.6 as 5
but we want maximum of
i + t*n >= a[i];
}
*/



int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int min_value = INT_MAX;
    int min_index = -1;
    int t[n];
    for (int i = 0; i < n; i++)
    {
        if ((a[i] - i) % n == 0)
        {
            t[i] = (a[i] - i) / n;
        }
        else if (a[i] - i < 0)
        {
            t[i] = 0;
        }
        else
        {
            t[i] = ((a[i] - i) / n) + 1;
        }
    }
    int ans[n];

    for (int i = 0; i < n; i++)
    {
        ans[i] = i + t[i] * n;
        if (ans[i] < min_value)
        {
            min_value = ans[i];
            min_index = i;
        }
    }

    cout<<min_index+1;

    /* 
    //in place passing min index to function go 
    int h = 0;

    std::vector<int> window;
    while (n--)
    {
        int a;
        cin >> a;
        window.push_back(a);
        if (window.at(min_index) > window.at(h))
        {
            min_index = h;
            min_value = window.at(min_index);
        }
        h++;
    }

    cout << go(window, min_index) + 1 << '\n'; */

    return 0;
}