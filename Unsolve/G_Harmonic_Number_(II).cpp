#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
ull sum(ull num)
{
    return (num * (num + 1)) / 2;
}

long long H(long long n)
{
    return (n * n) / sum(n);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, n;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        cin >> n;
        printf("Case %d: %lld\n", t, H(n));
        cout << n * n << " " << sum(n) << endl;
    }
    return 0;
}