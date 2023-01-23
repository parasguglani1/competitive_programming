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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
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
        updateTree(2 * node + 1, mid + 1, end, tree, arr, 2, 10);
    }
    else
    {
        updateTree(2 * node, start, mid, tree, arr, 2, 10);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
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
    int ans2 = query(tree, mid + 1, end, left, right, 2 * node+1);
    return (ans1 + ans2);
}

int main()
{
    int *arr = new int[100];
    int *tree = new int[100];
    int n;
    cin >> n;
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
    // updateTree(1, 0, n - 1, tree, arr, 2, 10);

    for (int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    int ans = query(tree, 0, 4, 2, 4, 1);
    cout << ans;
    return 0;
}
