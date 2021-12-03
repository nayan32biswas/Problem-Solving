#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
lli x;
lli solve(lli n)
{
    priority_queue<lli, vector<lli>, greater<lli>> que;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        que.push(x);
    }
    lli first, ans = 0;
    while (que.size() > 1)
    {
        first = que.top(), que.pop();
        first += que.top(), que.pop();
        que.push(first);
        ans += first;
    }
    // ans += que.top();
    return ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) && n)
    {
        printf("%lld\n", solve(n));
    }
}