#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli solve()
{
    int n, x;
    lli ans = LONG_LONG_MAX, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        sum += x;
        ans = min(ans, sum);
    }
    if (ans <= 0)
    {
        return -(ans - 1);
    }
    return 0;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int q, x;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        printf("%lld\n", solve());
    }

    return 0;
}