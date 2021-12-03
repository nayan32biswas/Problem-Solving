#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;

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
int primeDevesor(int num)
{
    if (num < Size && isP(num))
        return 2;
    int ans = 1, coun, i, x = 2;
    for (i = 0; x * x <= num; x = prime[++i])
        if (num % x == 0)
        {
            coun = 1;
            while (!(num % x))
            {
                num /= x;
                coun++;
            }
            ans *= coun;
        }
    if (num > 1)
        ans <<= 1;
    return ans;
}
void extractInteger(string &str)
{
    string temp = "";
    stringstream ss;
    ss << str;
    int number;
    while (!ss.eof())
    {
        ss >> temp;
        if (stringstream(temp) >> number)
        {
            cout << number << endl;
        }
        temp = "";
    }
}

int arr[Size];
int find(int mid)
{
    return arr[mid];
}
int binary_search_upper(int key, int n)
{
    int start = 0, End = n - 1;
    while (End - start > 1)
    {
        int mid = (start + End) / 2;
        if (find(mid) >= key)
            End = mid;

        else
            start = mid;
    }
    if (find(start) >= key)
        return start;
    return End;
}
int binary_search_lower(int key, int n)
{
    int start = 0, End = n - 1;
    while (End - start > 1)
    {
        int mid = (start + End) / 2;
        if (find(mid) <= key)
            start = mid;
        else
            End = mid;
    }
    if (find(End) <= key)
        return End;
    return start;
}
void solve()
{
    int n;
    scanf("%d", &n);
}
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: ", test);
        solve();
    }
    return 0;
}