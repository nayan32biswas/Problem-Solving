#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int x,  n, ans=0;
    map<int, int>store;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        ans = max(ans, ++store[x]);
    }
    cout<<ans<<endl;
}