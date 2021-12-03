#include<bits/stdc++.h>
using namespace std;
#define MX 111
vector <int>g[MX];
bool visit[MX], vis[MX];
int dis[MX];
int BFS(int i);

int main()
{
    freopen("graph.txt", "r", stdin);
    int n, m, x, y, test, i, J, ans, coun;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d",&n,&m);
        memset(visit, 0, sizeof(visit));
        coun=0;
        while(m--){
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            if(visit[x]==0) coun++;
            visit[x]=1;

        }
        ans = BFS(1);
        ans = coun-ans;
        if(ans<0) ans=0;
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
int BFS(int i){
    int len, J, coun=0;
    memset(vis, 0, sizeof(vis));
    vis[i] = 1;
    dis[i]=0;
    queue<int>Q;
    Q.push(i);
    while(!Q.empty()){
        i = Q.front();
        len = g[i].size();
        Q.pop();
        for(J=0; J<len; ++J){
            if(vis[g[i][J]]==1) coun+=dis[i];
            if(!vis[g[i][J]]){
                vis[g[i][J]] = 1;
                dis[g[i][J]] = dis[i]+1;
                Q.push(g[i][J]);
            }
        }
    }
    return coun;
}
