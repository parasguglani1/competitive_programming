/* Minimum In SubArray
Send Feedback
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1 */

#include <bits/stdc++.h>
using namespace std;
void buildTree(int node, int start, int end, int tree[], int arr[])
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid, tree, arr);
        buildTree(2 * node + 1, mid + 1, end, tree, arr);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void updateTree(int node, int start, int end, int tree[], int arr[], int idx, int value)
{

    if (start == end)
    {
        arr[idx] = value;
        tree[node] = value;
        return;
    }
    int mid = start + (end - start) / 2;
    if (idx > mid)
    {
        updateTree(2 * node + 1, mid + 1, end, tree, arr, 2, value);
    }
    else
    {
        updateTree(2 * node, start, mid, tree, arr, 2, value);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int *tree, int start, int end, int left, int right, int node)
{
    // if range is outside
    if (right < start || left > end)
    {
        return 0;
    }

    // if range is inside
    if (left <= start && right >= end)
    {
        return tree[node];
    }

    // if range is partially inside and partially outside
    int mid = start + (end - start) / 2;
    int ans1 = query(tree, start, mid, left, right, 2 * node);
    int ans2 = query(tree, mid + 1, end, left, right, 2 * node + 1);
    return min(ans1, ans2);
}

int main()
{
    int *arr = new int[100];
    int *tree = new int[100];
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    buildTree(1, 0, n - 1, tree, arr);

    for (int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < q; i++)
    {
        char c;
        int idx, value;
        cin >> c >> idx >> value;
        if (c == 'q')
        {
            int ans = query(tree, 0, 4, idx, value, 1);
            cout << ans << " ";
        }
        else
        {
            updateTree(1, 0, n - 1, tree, arr, idx, value);
        }
    }

    /*    for (int i = 1; i < 2 * n; i++)
       {
           cout << tree[i] << " ";
       }
       cout << endl; */

    return 0;
}
