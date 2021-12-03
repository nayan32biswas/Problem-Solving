#include <bits/stdc++.h>
using namespace std;
#define Size 10009
bool mark[Size];
vector<int>graph[Size];
void dfs(int node){
    mark[node] = 1;
    for(int i=0, len=graph[node].size(); i<len; i++)
        if(!mark[graph[node][i]]) dfs(graph[node][i]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, node, edge, x, y;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>node>>edge;
        for(int i=0; i<node; i++) graph[i].clear();
        memset(mark, 0, sizeof(mark));
        while(edge--){
            scanf("%d%d",&x, &y);
            x--, y--;
            graph[x].push_back(y);
        }
        int ans=0;
        for(int i=0; i<node; i++)
            if(graph[i].size()>0 && !mark[i])
                dfs(i), ans++;
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
