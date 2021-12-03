#include<bits/stdc++.h>
using namespace std;
bool vis[1010];
int mark[1010];
vector<int>v[1010];
bool bfs(int n){
    int u, v2;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        u=q.front();
        q.pop();
        vis[u]=1;
        mark[u]++;
        for(int j=0;j<v[u].size();j++){
            v2=v[u][j];
            if(mark[v2]==3) return true;
            if(vis[v2]==0)q.push(v2);
        }
    }
    return false;
}
int main()
{
    freopen("graph.txt", "r", stdin);
    int t, x, y;
    cin>>t;
    for(int i=1; i<=t; i++){
        int n,e;
        cin>>n>>e;
        for(int j=0;j<e;j++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bool p=0;
        for(int j=0;j<n;j++){
            if(bfs(j)==true){
                p=1;
                break;
            }
        }
        cout<<"Case "<<i<<": ";
        if(p){
            if(e<=2*n-4)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        else{
            if(e<=3*n-6)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        memset(mark,0,sizeof(mark));
        memset(v,0,sizeof(v));
        memset(vis,0,sizeof(vis));
    }

    return 0;
}
