#include <bits/stdc++.h>
using namespace std;
long long for_each()
{
    long long n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    if (a <= (float(b) / 2))
        return n * a;
    if (n & 1)
        return a + (n / 2) * b;
    return (n / 2) * b;
}
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
        printf("%lld\n", for_each());
    return 0;
}