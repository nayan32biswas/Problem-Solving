#include <bits/stdc++.h>
typedef long long int lli;
#define ull unsinged long long
using namespace std;
void solve()
{
    int n;
    double m;
    scanf("%d%lf", &n, &m);
    int success = ceil(n * m), x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x >= 50)
        {
            success--;
        }
    }

    puts(success <= 0 ? "YES" : "NO");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        // printf("Case %d: ", t);
        solve();
    }
    return 0;
}