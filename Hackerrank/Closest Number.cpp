#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli find_ans()
{
    lli a, b, x, power, low, high;
    scanf("%lld%lld%lld", &a, &b, &x);
    if (b < 0)
    {
        if (a == 1 and x == 1)
            return 1;
        return 0;
    }
    power = pow(a, b);
    a = power / x;
    low = a * x;
    high = (a + 1) * x;
    if (abs(power - low) > abs(power - high))
        return high;
    return low;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    lli test;
    scanf("%lld", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("%llu\n", find_ans());
    }
}