#include <bits/stdc++.h>
using namespace std;
#define Size 1005
vector <int>graph[Size];
bool mark[Size];
int many[Size];
bool ck;
void dfs(int node){
    mark[node] = true;
    int x = 0;
    for(auto v : graph[node]){
        if(graph[v].size()==0) x++;
        else if(!mark[v]) dfs(v);
    }
    if(x<3) ck=false;
    //cout<<node<<" "<<x<<endl;
}
int main()
{
    int n, x;
    cin>>n;
    for(int i=2; i<=n; i++){
        scanf("%d", &x);
        graph[x].push_back(i);
    }
    ck = true;
    dfs(1);
    if(ck) puts("Yes");
    else puts("No");
}
