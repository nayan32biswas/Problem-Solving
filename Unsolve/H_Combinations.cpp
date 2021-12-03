#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli coun;
lli nCr(lli n, lli r)
{
    if (n < (r << 1))
        r = n - r;
    lli ans = 1;
    for (int i = 1; i <= r; i++, n--)
    {
        ans *= n;
        ans /= i;
        ans %= 1000003;
        coun++;
    }
    return ans % 1000003;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ttt = clock();
    int test, a, b;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d%d", &a, &b);
        printf("Case %d: %lld\n", t, nCr(a, b));
    }
    ttt = clock() - ttt;
    printf("%lld  %d\n", coun, ttt);
    return 0;
}