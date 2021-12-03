#include <bits/stdc++.h>
using namespace std;
struct node
{
    int pos, time, cost;
    node() {}
    node(int a, int b, int c)
    {
        pos = a;
        time = b;
        cost = c;
    }
    bool operator<(const node &temp)
    {
        return time*temp.cost < temp.time*cost;
    }
};
void solve()
{
    int n, x, y;
    scanf("%d", &n);
    vector<node> arr;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        arr.push_back(node(i, x, y));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", arr[i].pos);
    }
    puts("");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        if (t > 1)
            puts("");
        solve();
    }
    return 0;
}