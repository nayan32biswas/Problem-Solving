#include <bits/stdc++.h>
using namespace std;
#define Size 10000009
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
int search(int s)
{
    int pos = lower_bound(prime.begin(), prime.end(), s) - prime.begin();
    while (prime[pos] > s)
        pos--;
    return max(0, pos);
}
int solve(int n)
{
    int half = n / 2 + 1;
    int start = search(half), End = search(n);
    if(prime[start]<half)start++;
    // printf("n: %d\nhalf: %d\nstart: %d %d\nEnd: %d %d\n", n, half, start, prime[start], End, prime[End]);
    return (End - start)+1;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    seive();
    int test, n;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
}