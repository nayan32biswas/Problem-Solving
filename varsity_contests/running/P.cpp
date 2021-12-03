#include <bits/stdc++.h>
using namespace std;
#define SIZE 100 + 5
vector<int> graph[SIZE];
int fromStart[SIZE], fromEnd[SIZE];
bool mark[SIZE];

int bfs(int source, int dis[])
{
    queue<int> que;
    memset(mark,  0, SIZE);
    mark[source] = true;
    que.push(source);
    while (!que.empty())
    {
        int current = que.front();
        que.pop();
        for (auto itr : graph[current])
        {
            if (mark[itr] == false)
            {
                mark[itr] = true;
                dis[itr] = dis[current] + 1;
                que.push(itr);
            }
        }
    }
}

int solve()
{
    int N, R, u, v, start, end, ans=0;
    scanf("%d%d", &N, &R);
    for(int i=0; i<N; i++)graph[i].clear();
    for (int i = 0; i < R; i++)
    {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    scanf("%d%d", &start, &end);
    memset(fromStart, 0, SIZE);
    memset(fromEnd, 0, SIZE);
    bfs(start, fromStart);
    bfs(end, fromEnd);
    for(int i=0; i<N; i++){
        ans = max(ans, fromStart[i]+fromEnd[i]);
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: %d\n", t, solve());
    }
    return 0;
}