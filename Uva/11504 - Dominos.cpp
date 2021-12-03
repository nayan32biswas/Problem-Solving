#include <bits/stdc++.h>
using namespace std;
#define Size 100002
bool mark[Size];
stack<int>stk;
vector<int>graph[Size];
void top_sort(int node) {
    if(mark[node]==true)
        return;
    mark[node] = true;
    for(auto it : graph[node]) {
        if(mark[it]==false)
            top_sort(it);
    }
    stk.push(node);
}
void dfs(int node) {
    if(mark[node])
        return;
    mark[node] = true;
    for(auto it : graph[node]) {
        if(!mark[it]) {
            dfs(it);
        }
    }
}
void Find(int node) {

    while(!stk.empty())stk.pop();
    memset(mark, 0, sizeof(mark));

    for(int i=1; i<=node; i++) {
        if(mark[i]==false) {
            top_sort(i);
        }
    }
    int ans = node-stk.size();
    memset(mark, 0, sizeof(mark));
    while(!stk.empty()){
        if(mark[stk.top()]==false){
            dfs(stk.top());
            ans++;
        }
        stk.pop();
    }
    printf("%d\n", ans);
}
void solve() {
    int n, m, x, y, a, b;
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; i++)
        graph[i].clear();

    for(int i=0; i<m; i++) {
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
    }
    Find(n);
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--)
        solve();
}
