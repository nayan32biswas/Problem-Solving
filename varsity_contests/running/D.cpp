#include <bits/stdc++.h>
using namespace std;
#define SIZE 100005

int X;
bool mark[SIZE];
int parent[SIZE];
set<int> graph[SIZE];
vector<int> temp_graph[SIZE], memo;

void first_dfs(int node){
    mark[node] = true;
    for (auto it : temp_graph[node]){
        if (!mark[it]){
            parent[it] = node;
            graph[node].insert(it);
            first_dfs(it);
        }
    }
}

void dfs(int node){
    if (mark[node])
        return;
    for (auto it : graph[node]){
        if (X <= 0)return;
        if (!mark[it])dfs(it);
    }
    if (X > 0){
        mark[node] = true, X--;
        memo.push_back(node);
    }
}
void solve(){
    int N, u, v;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        graph[i].clear();
        temp_graph[i].clear();
        mark[i] = 0;
    }
    for (int i = 1; i < N; i++){
        scanf("%d%d", &u, &v);
        u--, v--;
        temp_graph[u].push_back(v);
        temp_graph[v].push_back(u);
    }
    parent[0] = 0;
    first_dfs(0);
    memset(mark, 0, sizeof(mark));

    int cas, Q, U;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++){
        scanf("%d%d", &cas, &U);
        U--;
        if (cas == 1){
            scanf("%d", &X);
            memo.clear();
            dfs(U);
            for (auto it : memo){
                graph[parent[it]].erase(it);
                graph[it].clear();
            }
            // cout<<"\t"<<X<<" remain\t"; for(int i=0; i<N; i++)cout<<mark[i]<<" ";puts("");
        }
        else
            printf("%d\n", mark[U]);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("rand_input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++){
        printf("Case %d:\n", t);
        solve();
    }
}
