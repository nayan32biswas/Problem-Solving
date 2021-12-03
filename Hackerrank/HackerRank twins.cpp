#include <bits/stdc++.h>
using namespace std;
bool mark[1000010];
int LOW;

bool is_prime(int num)
{
    return !mark[num - LOW];
}

void simpleSieve(int limit, vector<int> &prime)
{
    memset(mark, false, sizeof(mark));
    for (int i = 2; i <= limit; ++i)
    {
        if (mark[i] == false)
        {
            prime.push_back(i);
            for (int j = i; j <= limit; j += i)
                mark[j] = true;
        }
    }
}
void primesInRange(int low, int high)
{
    int limit = floor(sqrt(high)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime);
    int n = high - low + 1;
    memset(mark, false, sizeof(mark));
    mark[1] = true;
    for (int i = 0; i < prime.size(); i++)
    {
        int loLim = floor(low / prime[i]) * prime[i];
        if (loLim < low)
            loLim += prime[i];
        if (loLim == prime[i])
            loLim += prime[i];
        for (int j = loLim; j <= high; j += prime[i])
            mark[j - low] = true;
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int low, high, ans = 0;
    cin >> low >> high;
    LOW = low;
    primesInRange(low, high);
    low = max(3, low);
    if (!(low & 1))
        low++;
    if (!(high & 1))
        high--;

    for (; low < high; low += 2)
    {
        if (is_prime(low) && is_prime(low + 2))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
