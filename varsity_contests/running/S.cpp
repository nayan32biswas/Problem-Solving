#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000005
#define MOD 1000003
typedef long long int lli;
// Do initial precalculation
lli Fact[SIZE];
lli invFact[SIZE];
lli FastPowerCalc(lli a, lli n, lli mod)
{
    if (n == 0)
        return 1;
    lli ret = FastPowerCalc(a, n / 2, mod);
    ret = (ret * ret) % mod;
    if (n % 2 == 1)
        ret = (ret * a) % mod;
    return ret;
}
lli ModularInverseFast(lli n, lli mod)
{
    return FastPowerCalc(n, (mod - 2), mod);
}
void PreCalc(lli n, lli mod)
{
    Fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        Fact[i] = (Fact[i - 1] * i) % mod;
        invFact[i] = ModularInverseFast(Fact[i], mod);
    }
}
/* Answer per query in O (1)*/
lli nCr(lli n, lli r, lli mod)
{
    lli Up = Fact[n];
    lli Down1 = invFact[r];
    lli Down2 = invFact[n - r];
    lli ret = (Up * Down1) % mod;
    ret = (ret * Down2) % mod;
    return ret;
}
long long nCrRegular(long long n, long long r, long long mod)
{
    if (n < (r << 1))
        r = n - r;
    long long ans = 1;
    for (int i = 1; i <= r; (ans = (ans * n) % mod, ans /= i), i++, n--)
        ;
    return ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test, n, k;
    PreCalc(SIZE, MOD);
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d%d", &n, &k);
        printf("Case %d: %lld\n", t, nCr(n, k, MOD));
    }
}