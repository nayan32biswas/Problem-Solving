#include <bits/stdc++.h>
using namespace std;
map<int, int> ans;
int main()
{
    // freopen("input.txt", "r", stdin);

    int n, q, x;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (!ans[x])
        {
            ans[x] = i;
        }
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x);
        x = ans[x];
        if (!x)
        {
            puts("-1");
        }
        else
        {
            printf("%d\n", x-1);
        }
    }
    return 0;
}