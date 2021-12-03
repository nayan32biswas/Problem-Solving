#include <bits/stdc++.h>
using namespace std;

long long solve()
{
    long long N;
    cin >> N;
    long long last = 1;
    long long root = sqrt(N) + 1;
    for (long long i = root; i > 1; i--)
    {
        if (N % i == 0)
        {
            last = i;
            break;
        }
    }
    return last + N / last - 2;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
        cout << solve() << endl;
}