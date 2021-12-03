#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
map<lli, int> store;
void store_sqrt(lli num)
{
    for (lli i = 2; i <= num; i++)
    {
        store[i * i] = i;
    }
}

void solve(lli num)
{

    lli ans = 0, temp;
    bool find = true;
    while (find)
    {
        find = false;
        for (int i = 2; i < num; i++)
        {
            while (store[num])
            {
                num = store[num];
                cout << num << endl;
                ans++;
            }
            temp = store[num * i];
            cout << "temp " << num << " " << i << " " << temp << endl;
            if (temp > 0)
            {
                find = true;
                num = temp;
                ans += 2;
            }
        }
    }
    cout << num << " " << ans << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    lli num;
    scanf("%lld", &num);
    store_sqrt(num);
    solve(num);
    return 0;
}
