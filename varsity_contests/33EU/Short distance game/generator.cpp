#include <bits/stdc++.h>
using namespace std;
long long int Find(long long int low, long long int hi)
{
    return random() % hi + low;
}

#define Size 10000000
typedef long long lli;
vector<unsigned> pri((Size >> 6) + 5), prime;
#define setBits(n) (pri[n >> 6] |= (1 << ((n >> 1) & 31)))
#define checkBit(n) (pri[n >> 6] & (1 << ((n >> 1) & 31)))
#define isP(n) ((n == 2) || (n > 1 && (n & 1) && !checkBit(n)))
void seive()
{
    unsigned i, j;
    for (i = 3; i * i <= Size; i += 2)
        if (!checkBit(i))
        {
            for (j = i * i; j < Size; j += (i << 1))
                setBits(j);
        }
    prime.push_back(2);
    for (i = 3; i < Size; i += 2)
        if (!checkBit(i))
            prime.push_back(i);
}

void prime_generate()
{
    freopen("prime_input.txt", "w", stdout);
    long long test = 100;
    seive();
    reverse(prime.begin(), prime.end());
    cout << test << endl;
    for (long long i = 0; i < test; i++)
        cout << prime[i] << endl;
}
void non_peime()
{
    freopen("none_input.txt", "w", stdout);
    long long N = 999999999000, test = 100;
    // freopen("none_input_1.txt", "w", stdout);
    // long long N = 999999990000, test = 100;
    cout << test << endl;
    for (long long i = N; i < N + test; i++)
        cout << i << endl;
}
void generate()
{
    srand(time(NULL));
    freopen("input.txt", "w", stdout);
    long long test;
    cin>>test;
    cout << test << endl;
    for (long long i = 0; i < test; i++)
        cout << Find(1, 100000000000) << endl;
}
int main()
{
    // generate();
    // non_peime();
    prime_generate();
}