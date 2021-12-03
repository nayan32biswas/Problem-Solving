#include <bits/stdc++.h>
using namespace std;
#define Size 100009
int Min, arr[Size];
bool mark[Size];
vector<int>graph[Size];
void dfs(int node){
    Min = min(Min, arr[node]);
    mark[node] = 1;
    for(auto it : graph[node])if(!mark[it]) dfs(it);
}
int main()
{
    int n, m, x, y;
    long long ans=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<m; i++){
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1; i<=n; i++)if(!mark[i]){
        Min = arr[i];
        dfs(i);
        ans += Min;
    }
    for(int i=1; i<=n; i++)if(!mark[i]) ans += arr[i];
    cout<<ans<<endl;
}
