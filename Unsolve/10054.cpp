#include <bits/stdc++.h>
using namespace std;
#define Size 51
vector<int> graph[Size];
map<int, int> common;
stack<int> stk;
bool mark[Size];

void top_sort(int node)
{
    mark[node] = true;
    for (auto it : graph[node])
    {
        if (mark[it] == false)
        {
            top_sort(it);
        }
    }
    stk.push(node);
}
bool find_in(int index, int value)
{
    for (auto it : graph[index])
        if (it == value)
            return true;
    return false;
}
void each_case()
{
    for (int i = 0; i < Size; i++)
        graph[i].clear();
    int N, x, y;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &x, &y);
        if (x == y)
        {
            common[x]++;
        }
        else
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }
    int start = x;
    while (!stk.empty())
        stk.pop();
    memset(mark, 0, sizeof(mark));
    top_sort(start);
    vector<pair<int, int>> ans;
    start = stk.top();
    stk.pop();
    x = start;
    while (!stk.empty())
    {
        if (common[x])
        {
            int temp = common[x];
            common[x] = 0;
            for (int i = 0; i < temp; i++)
            {
                ans.push_back(make_pair(x, x));
            }
        }
        ans.push_back(make_pair(x, stk.top()));
        x = stk.top();
        stk.pop();
    }
    if (common[x])
    {
        int temp = common[x];

        for (int i = 0; i < temp; i++)
        {
            ans.push_back(make_pair(x, x));
        }
    }
    ans.push_back(make_pair(x, start));
    if (ans.size() != N)
    {
        for (auto it : ans)
        {
            printf("%d %d\n", it.first, it.second);
        }
        puts("");
        puts("some beads may be lost");
    }
    else if (find_in(start, x) && find_in(x, start))
    {
        for (auto it : ans)
        {
            printf("%d %d\n", it.first, it.second);
        }
        puts("");
    }
    else
    {
        puts("some beads may be lost");
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        if (t != 1)
            puts("");
        printf("Case #%d\n", t);
        each_case();
    }
    return 0;
}