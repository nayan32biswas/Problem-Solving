#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli solve()
{
    lli x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    if (x1 == x2 and y1 == y2)
        return 1;
    if (x1 == x2 or y1 == y2)
        return max(abs(x1 - x2), abs(y1 - y2)) + 1;
    lli dx = abs(x1 - x2);
    lli dy = abs(y1 - y2);

    lli gcd, up, down;
    gcd = __gcd(dx, dy);
    up = dx / gcd;
    down = dy / gcd;
    return 1 + (dy / down);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: %lld\n", t, solve());
    }
    return 0;
}