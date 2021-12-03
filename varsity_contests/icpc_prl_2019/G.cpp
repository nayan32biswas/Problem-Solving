#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;
#define Size 10000009

lli phi[Size + 10], sum[Size];
void totient()
{
    for (lli i = 1; i < Size; i++)
        phi[i] = i;
    for (lli p = 2; p < Size; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p - 1;
            for (lli i = 2 * p; i < Size; i += p)
            {
                phi[i] = (phi[i] / p) * (p - 1);
            }
        }
    }
}
void storeSum()
{
    sum[1] = 1;
    for (lli i = 2; i < Size; i++)
    {
        sum[i] = sum[i - 1] + phi[i] * 2;
    }
}
lli find(lli n)
{
    return sum[n];
}
lli binary_search_lower(lli P, lli N)
{
    lli start = 1, End = N, mid, temp;
    while (End - start > 1)
    {
        mid = (start + End) / 2;
        temp = find(N / mid);
        // cout << mid << " " << (N / mid) << " " << temp << "\t ";
        if (temp >= P)
        {
            start = mid;
            
        }
        else
            End = mid;
    }
    temp = find(N / start);
    // printf("\t\t%lld.......%lld %lld\n", temp, start, End);
    if (temp >= P)
    {
        return start;
    }
    return End;
}
void solve()
{

    lli N, P;
    scanf("%lld%lld", &N, &P);
    if (P > N * N)
        puts("-1");
    else
    {
        printf("%lld\n", binary_search_lower(P, N));
    }
}
int temp[20];
int main()
{
    freopen("input.txt", "r", stdin);
    totient();
    storeSum();
    lli test;
    scanf("%lld", &test);
    for (lli t = 1; t <= test; t++)
    {
        printf("Case %lld: ", t);
        solve();
    }
    return 0;
}