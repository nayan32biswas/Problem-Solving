#include <bits/stdc++.h>
#define SIZ 10000
using namespace std;
vector<int>V[SIZ];
int visite[SIZ];
bool vis[SIZ];
int bfs(int node)
{
    int len, i, v, coun;
    queue<int>Q;
    Q.push(1);

    for(node+=5; node>=0; visite[node]=0, vis[node]=0, node--);
    while(!Q.empty()){
        node = Q.front(); Q.pop();
        len = V[node].size();
        for(i=0; i<len; i++){
            v = V[node][i];
            if(visite[v]>2 && vis[v]==0){
                coun++;
                vis[v]=1;
            }
            if(!visite[v]){
                Q.push(v);
            }
            visite[v]++;
            cout<<visite[v]<<' ';
        }
    }
    cout<<endl<<coun<<endl;
    if(coun>3) return false;
    return true;
}
int main()
{
    freopen("graph.txt", "r", stdin);
    int test, node, edge, x, y;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>node>>edge;
        while(edge--){
            scanf("%d%d", &x, &y);
            x--, y--;
            V[x].push_back(y);
            V[y].push_back(x);
        }
        printf("Case %d: ", t);
        if(bfs(node)==true) puts("No");
        else puts("Yes");
    }
    return 0;
}
