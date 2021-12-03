#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long int lli;
using namespace std;
#define Size 35
vector<lli> coins, temp;
void store(int p)
{
    temp.push_back(1);
    for (int i = 1; i < 32; i++)
        temp.push_back(temp[i - 1] * 2);
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] + p != 0)
        {
            coins.push_back(temp[i] + p);
        }
    }
    sort(coins.begin(), coins.end(), greater<lli>());
}
int minCoins(int m, int V)
{
    if (V == 0)
        return 0;

    int res = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        if (coins[i] <= V)
        {
            int sub_res = minCoins(m, V - coins[i]);

            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}
void solve()
{
    int n, p;
    scanf("%d%d", &n, &p);
    store(p);
    int ans = minCoins(coins.size(), n);
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}
