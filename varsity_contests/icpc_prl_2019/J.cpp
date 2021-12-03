#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;
#define Size 10000000
#define lcm(a, b) a / __gcd(a, b) * b
vector<lli>arr;
void solve()
{

    lli N, K, x, Max = -1000, Min = INT_MAX, ans = 1;
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &x);
        Max = max(Max, x);
        Min = min(Min, x);
    }
    // cout<<Min<<" "<<Max<<endl;
    ans = Min*Max;

    if (ans == Max)
    {
        ans *= Max;
    }

    cout << ans << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: ", t);
        solve();
    }
    return 0;
}