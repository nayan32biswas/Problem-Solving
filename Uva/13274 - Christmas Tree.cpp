#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int K;
bool mark[Size];
vector<int>graph[Size], ans[Size];
int dfs(int node) {
    mark[node] = true;
    ans[node].clear();
    for(auto it : graph[node]) {
        if(!mark[it]) {
            if(graph[it].size()>=K) {
                ans[node].push_back(dfs(it));
            } else
                ans[node].push_back(1);
        }
    }
    if(ans[node].size()<K)
        return 1;
    sort(ans[node].begin(), ans[node].end(), greater<int>());
    int sum = 1;
    for(int i=0; i<K; i++)
        sum += ans[node][i];
    return sum;
}
int solve() {
    int node, x, y;
    scanf("%d%d", &node, &K);
    for(int i=0; i<node; i++)
        graph[i].clear();

    for(int i=1; i<node; i++) {
        scanf("%d%d", &x, &y);
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(graph[0].size()<K)
        return 1;
    memset(mark, 0, sizeof(mark));
    return dfs(0);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        printf("Case %d: %d\n", t, solve());
    }
    return 0;
}

