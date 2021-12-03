#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
map<lli, lli> mark;
lli max(lli a, lli b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    lli n, m;
    while (scanf("%lld%lld", &n, &m) != EOF)
    {
        lli x;
        mark.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            if (x)
                mark[x]++;
        }
        if (n == 1)
        {
            puts("0");
            continue;
        }
        lli ans = 0, prev = 0, temp;
        for (auto it : mark)
        {
            temp = (it.first * it.second) - max(it.first - prev, it.second);
            if (temp > 0)
                ans += temp;
            prev = it.first;
        }
        cout << ans << endl;
    }
    return 0;
}