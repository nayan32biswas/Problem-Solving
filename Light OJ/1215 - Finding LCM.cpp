#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef map<lli, int> mpp;
#define lcm(a, b) a / __gcd(a, b) * b
lli a, b, L;

mpp divisor(lli num)
{
    mpp temp;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            while (num % i == 0)
            {
                num /= i;
                temp[i]++;
            }
        }
    }
    if (num > 1)
        temp[num]++;
    return temp;
}
void store(mpp &value, mpp &common)
{
    for (auto it : value)
    {
        common[it.first] = max(it.second, common[it.first]);
    }
}
void show(mpp &value)
{
    for (auto it : value)
        cout << "(" << it.first << "," << it.second << ")\t";
    puts("");
}
void solve()
{
    scanf("%lld%lld%lld", &a, &b, &L);
    if (L % a > 0 || L % b > 0)
    {
        puts("impossible");
        return;
    }
    mpp aa, bb, ll, common;
    lli ans = 1;
    aa = divisor(a);
    bb = divisor(b);
    ll = divisor(L);

    store(aa, common);
    store(bb, common);
    bool imposible = true;
    for (auto it : ll)
    {
        if (common[it.first] == it.second)
            continue;
        ans *= pow(it.first, it.second);
    }
    cout << ans << endl;
}
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
}