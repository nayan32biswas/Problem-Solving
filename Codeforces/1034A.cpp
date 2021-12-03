#include <bits/stdc++.h>
using namespace std;
#define Size 4000
int arr[300005], ggg;
int count_fact[15000005];

unsigned pri[(Size >> 6) + 5];
vector<unsigned> prime;
#define setBits(n) (pri[n >> 6] |= (1 << ((n >> 1) & 31)))
#define checkBit(n) (pri[n >> 6] & (1 << ((n >> 1) & 31)))
#define isP(n) ((n == 2) || (n > 1 && (n & 1) && !checkBit(n)))
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

void primeDevesor(int num)
{
    if (num < Size && isP(num))
    {
        count_fact[num]++;
        return;
    }
    int ans = 1, coun, i, x = 2;
    for (i = 0; x * x <= num; x = prime[++i])
    {
        if (num % x == 0)
        {
            coun = 1;
            while (!(num % x))
            {
                num /= x;
            }
            // cout << x << " ";
            count_fact[x]++;
        }
    }
    if (num > 1)
    {
        // cout << num << " ";
        count_fact[num]++;
    }
}

int solve(int n)
{
    if (n == 1)
        return -1;
    int div;
    while (ggg > 1)
    {
        div = ggg;
        arr[0] /= div;
        ggg = arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i] /= div;
            ggg = __gcd(ggg, arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        primeDevesor(arr[i]);
    }
    int ans, first = 0, second = 0, temp;
    for (auto it : count_fact)
    {
        if (it)
        {
            temp = max(first, it);
            if (first < temp)
            {
                second = first;
                first = temp;
            }
        }
    }
    first == n ? ans = second : ans = first;
    // cout << first << " " << second << endl;
    if (ans == 0)
        return -1;
    return n - ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    seive();
    scanf("%d", &n);
    scanf("%d", &ggg);
    arr[0] = ggg;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &arr[i]);
        ggg = __gcd(ggg, arr[i]);
    }
    printf("%d\n", solve(n));
    return 0;
}
