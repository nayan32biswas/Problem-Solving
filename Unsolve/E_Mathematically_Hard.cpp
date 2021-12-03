#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
#define NumSize 5000005
vector<ull> coprime(NumSize + 5), q_sum(NumSize + 5);
void computeTotient()
{
    for (int i = 2; i <= NumSize; i++)
        coprime[i] = i;
    for (int p = 2; p <= NumSize; p++)
    {
        if (coprime[p] == p)
        {
            coprime[p] = p - 1;
            for (int i = 2 * p; i <= NumSize; i += p)
            {
                coprime[i] = (coprime[i] / p) * (p - 1);
            }
        }
    }
}

void store_coprime()
{
    computeTotient();
    for (int i = 2; i < NumSize; i++)
    {
        coprime[i] = pow(coprime[i], 2);
        q_sum[i] = q_sum[i-1]+coprime[i];
    }
}
ull ans(int a, int b){
    // ull sum = 0;
    // for(int i=a; i<=b; sum+=coprime[i], i++);
    // return sum;
    return q_sum[b] - q_sum[--a];
}
int main()
{
    // freopen("input.txt", "r", stdin);
    store_coprime();
    int test, a, b;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        scanf("%d%d", &a, &b);
        printf("Case %d: %llu\n", t, ans(a, b));
    }
    return 0;
}