#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int ans = 0, n;
    scanf("%d", &n);
    while (n--)
    {
        int x, coun = 0;
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &x);
            if (x > 5)
                coun++;
        }
        if (coun >= 3)
            ans++;
    }
    printf("%d\n", ans);
}
int main()
{
    // freopen("input.txt","r",stdin);
    int test = 0;
    // scanf("%d", &test);
    for (int t = 0; t <= test; t++)
    {
        // printf("Case %d: ", t);
        solve();
    }
    return 0;
}