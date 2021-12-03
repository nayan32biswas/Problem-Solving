#include <bits/stdc++.h>
typedef long long int lli;
#define ull unsinged long long
using namespace std;

void solve()
{
    int n, x, y;
    map<lli, lli> left, right;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        left[x]++;
        right[y]++;
    }
    lli ans = 0;
    for (auto it : left)
    {
        ans += it.second * right[it.first];
    }
    printf("%lld\n", ans);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        solve();
    }
    return 0;
}