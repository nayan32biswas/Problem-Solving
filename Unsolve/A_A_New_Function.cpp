#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli find_each(lli num)
{
    lli sum = 1, x;
    for (int p = 2; p * p <= num; p++)
    {
        if (num % p == 0)
        {
            lli d = 0;
            while (num % p == 0)
            {
                num /= p;
                d++;
            }
            sum = sum * (pow(p, (d + 1)) - 1) / (p - 1);
        }
    }
    if (num > 1)
        sum = sum * (pow(num, (1 + 1)) - 1) / (num - 1);
    return sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, num;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d", &num);
        printf("Case %d: %lld\n", t, find_each(num));
    }
    return 0;
}