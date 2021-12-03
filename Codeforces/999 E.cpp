#include <bits/stdc++.h>
using namespace std;
vector<int>graph[5001];
stack<int>Stack;
bool mark[5001];
void dfs(int node){
    mark[node] = 1;
    for(auto it : graph[node])
        if(!mark[it]) dfs(it);
}
void topSort(int node){
    mark[node] = 1;
    for(auto it : graph[node])
        if(!mark[it]) topSort(it);
    Stack.push(node);
}
int main() {
    int n, m, s, u, v, ans = 0;
    scanf("%d%d%d", &n, &m, &s);
    for(int i=0; i<m; i++) {
        scanf("%d%d", &u, &v);
        graph[--u].push_back(--v);
    }
    for(int i=0; i<n; i++)if(!mark[i]) topSort(i);
    memset(mark, 0, sizeof(mark));
    dfs(--s);
    while(!Stack.empty()){
        u = Stack.top(), Stack.pop();
        if(!mark[u]) dfs(u), ans++;
    }
    cout<<ans<<endl;
}
