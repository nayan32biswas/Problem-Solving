#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int T;
    long long a, b, gcd;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%lld%lld", &a, &b);
        gcd = __gcd(a, b);
        printf("%lld %lld\n", gcd, (a / gcd * b));
    }
    return 0;
}