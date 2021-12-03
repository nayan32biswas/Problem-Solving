#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
vector<int> arr;
int n, m;

bool find(lli mid)
{
    lli sum = 0;
    int coun = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            coun = m + 1;
            break;
        }
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            coun++;
        }
    }
    return coun <= m;
}

lli binary_search_lower()
{
    lli start = 0, End = INT_MAX, mid;
    while (End - start > 1)
    {
        mid = (start + End) / 2;
        if (find(mid))
            End = mid;
        else
            start = mid;
    }
    if (find(start))
        return start;
    return End;
}
void solve()
{
    scanf("%d%d", &n, &m);
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = binary_search_lower();
    printf("%d\n", ans);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: ", t);
        solve();
    }
    return 0;
}