#include <bits/stdc++.h>
using namespace std;
#define Size 1000005
int prime[Size / 5], p;
bool isPrime(int n)
{
    if (n < 3 || !(n & 1))
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)

            return false;
    }
    return true;
}
void generate(int n)
{
    p = 0;
    prime[p++] = 2;
    for (int i = 3; i < n; i += 2)
        if (isPrime(i))
            prime[p++] = i;
}
void primeFactor(long long n)
{
    if (n < 2)
    {
        puts("Not composit");
        return;
    }
    int ans = 0;
    for (int i = 0, x = prime[i]; x * x <= n; i++, x = prime[i])
    {
        while (n % x == 0)
        {
            n /= x;
            ans += x;
        }
    }
    if (n > 1)
        ans += n;

    printf("%d\n", ans);
}
int main()
{
    // freopen("input5.txt", "r", stdin);
    // freopen("output5.txt", "w", stdout);
    generate(Size);
    int test;
    long long n;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        scanf("%lld", &n);
        primeFactor(n);
    }
    return 0;
}