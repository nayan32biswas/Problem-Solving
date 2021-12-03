#include <bits/stdc++.h>
using namespace std;
#define Size 1000005
bool mark[Size], reStack[Size], cycle;
vector<int> graph[Size];
stack<int> stk;
void topSort(int node)
{
    if (cycle)
        return;
    mark[node] = true;
    reStack[node] = true;
    for (auto it : graph[node])
    {
        if (reStack[it] == true)
        {
            cycle = true;
            return;
        }
        else if (mark[it] == false)
            topSort(it);
    }
    reStack[node] = false;
    stk.push(node);
}
void solve(int n, int m)
{
    memset(mark, 0, sizeof(mark));
    memset(reStack, 0, sizeof(reStack));
    while (!stk.empty())
        stk.pop();
    int a, b;
    for (int i = 0; i <= n; i++)
    {
        graph[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
    }
    cycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == false)
        {
            topSort(i);
        }
    }
    if (cycle)
    {
        puts("IMPOSSIBLE");
        return;
    }
    while (!stk.empty())
    {
        printf("%d\n", stk.top());
        stk.pop();
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            return 0;
        solve(n, m);
    }
}