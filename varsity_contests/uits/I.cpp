#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, ans = 1;
    string str;
    map<string, int> store;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        store[str]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (store[str] == 0)
        {
            ans = 0;
        }
        else
            store[str]--;
    }
    puts(ans ? "Croissant" : "Troll");
}
int main()
{
    // freopen("input.txt","r",stdin);
    int test = 0;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        // printf("Case %d: ", t);
        solve();
    }
    return 0;
}