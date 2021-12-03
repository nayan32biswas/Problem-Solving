#include <bits/stdc++.h>
using namespace std;

#define Size 1000000
int pri[Size / 8];

#define setBits(n) (pri[n >> 6] |= (1 << ((n >> 1) & 31)))
#define checkBit(n) (pri[n >> 6] & (1 << ((n >> 1) & 31)))

typedef long long int lli;
typedef vector<int> vec;
vector<int> prime;
void seive()
{
    unsigned i, j;
    for (i = 3; i * i <= Size; i += 2)
    {
        if (!checkBit(i))
        {
            for (j = i * i; j < Size; j += (i << 1))
                setBits(j);
        }
    }
    prime.push_back(2);
    for (i = 3; i < Size; i += 2)
        if (!checkBit(i))
            prime.push_back(i);
}
void primeFactor(lli n, set<lli> &combine)
{
    vec factor;
    for (int i = 0, x = prime[i]; x * x <= n; i++, x = prime[i])
    {
        while (n % x == 0)
        {
            n /= x;
            factor.push_back(x);
        }
    }
    if (n > 1)
        factor.push_back(n);

    /***************/
    int len = factor.size();
    for (int i = 0; i < len; i++)
    {
        int temp = factor[i];
        combine.insert(temp);
        for (int j = i + 1; j < len; j++)
        {
            temp *= factor[j];
            combine.insert(temp);
        }
    }
}
lli Find(lli n, lli k)
{
    lli t = n / k;
    return t + (k * t * (t - 1) / 2);
}
int main()
{
    lli n;
    set<lli> ans, combine;
    cin >> n;
    seive();
    primeFactor(n, combine);
    for (auto it : combine)
        ans.insert(Find(n, it));

    ans.insert(1);
    ans.insert((n * (n + 1)) / 2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    puts("");
}