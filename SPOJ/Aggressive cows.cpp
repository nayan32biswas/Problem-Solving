#include <bits/stdc++.h>
using namespace std;
#define Size 10000009
vector<int> arr;
int n, C;
int upper_bound_binary_search(int key)
{
    int start = 0, End = arr.size(), mid;
    while (start < End)
    {
        mid = start + (End - start) / 2;
        if (arr[mid] <= key)
            start = mid + 1;
        else
            End = mid - 1;
    }
    start = max(start - 2, 0);
    while (start < n && arr[start] < key)
        start++;
    return start;
}
bool is_take(int mid)
{
    int coun = 1;
    int next_point = upper_bound_binary_search(arr[0] + mid);
    while (next_point < n)
    {
        coun++;
        next_point = upper_bound_binary_search(arr[next_point] + mid);
    }
    return coun >= C;
}
int solve()
{
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int start = arr[0], End = arr[n - 1], mid;
    while (start <= End)
    {
        mid = start + (End - start) / 2;
        if (is_take(mid))
        {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else
            End = mid - 1;
    }
    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d%d", &n, &C);
        printf("%d\n", solve());
    }
}