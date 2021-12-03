#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
#define Max_pow 42
ull threePow[60];
void store()
{
    threePow[0] = 1;
    for (int i = 1; i < Max_pow; i++)
    {
        threePow[i] = threePow[i - 1] * 3;
        if (threePow[i] < threePow[i - 1])
            break;
    }
    reverse(threePow, threePow + Max_pow);
}
ull maxAns;
void find_rec(ull n, ull now, int pos)
{
    if (now > maxAns)
        return;
    for (int i = pos; i < Max_pow; i++)
    {
        now += threePow[i];
        if (now >= n)
        {
            maxAns = min(maxAns, now);
        }
        find_rec(n, now, i + 1);
        now -= threePow[i];
    }
}
void solve()
{
    maxAns = UINT64_MAX;
    ull n;
    scanf("%llu", &n);
    find_rec(n, 0, 0);
    printf("%llu\n", maxAns);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    store();
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        solve();
    }

    return 0;
}
