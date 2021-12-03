#include <bits/stdc++.h>
using namespace std;
#define Size 10009
vector<int>graph[Size], Copy;
int mark[Size];
int ans;
void dfs(int node, int parents){
    mark[node] = Copy[node];
    if(mark[node]!=mark[parents]) ans++;
    for(auto it : graph[node]){
        if(!mark[it]){
            dfs(it, node);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, x, y;
    cin>>n;
    vector<int>color(n+1);
    for(int i=1; i<n; i++){
        cin>>x;
        graph[x].push_back(i+1);
    }
    for(int i=1; i<=n; i++)cin>>color[i];
    Copy = color;
    dfs(1, 1);
    cout<<ans+1<<endl;
    return 0;
}

