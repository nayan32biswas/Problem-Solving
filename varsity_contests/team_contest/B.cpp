#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        puts("-1");
        return;
    }
    n -= 2;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            puts("-1");
            return;
        }
    }
    printf("2 %d\n", n);
}
int main()
{
    solve();
    return 0;
}