#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
vector<set<int>> adj;
vector<int> par(maxn);
vector<bool> state(maxn);

void dfs(int node, int parent){
    par[node] = parent;
    for(auto x: adj[node]){
        if(x == parent) continue;
        dfs(x, node);
    }
}
int x = 0;
void update(int u, int p){
    if(state[u]){
        return;
    }
    for(auto f: adj[u]){
        if(f == p) continue;
        if(!state[f]){
            update(f, par[f]);
            if(!x) {
                return;
            }
            if(adj[u].size() == 1) break;
        }
    }
    if(!state[u]) {
        state[u] = 1;
        x--;
        if(p != -1) adj[p].erase(u);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    freopen("rand_input.txt", "r", stdin);freopen("output.txt", "w", stdout);

    int t; scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++){
        int n;
        scanf("%d", &n);
        adj.clear();
        set<int> s;
        for(int i = 0; i <= n; i++) {
            adj.push_back(s);
            state[i] = 0;
            par[i] = 0;
        }
        adj[1].insert(-1);
        for(int j = 0; j < n-1; j++){
            int u, v; scanf("%d%d", &u, &v);
            adj[u].insert(v);
            adj[v].insert(u);
        }
        dfs(1, -1);
        int q; scanf("%d", &q);
        vector<int> res;
        while(q--){
            int type; scanf("%d", &type);
            if(type == 1){
                int u;
                scanf("%d%d", &u, &x);
                update(u, par[u]);

            }
            else{
                int u;
                scanf("%d", &u);
                if(state[u] == 1) res.push_back(1);
                else res.push_back(0);
            }
        }
        printf("Case %d:\n", cs);
        for(auto f: res) {
            printf("%d\n", f);
        }

    }
}