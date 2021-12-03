#include <bits/stdc++.h>
using namespace std;
#define Size 2005
int many;
bool mark[Size];
vector<int>order, graph[Size];
void top_sort(int node){
    if(mark[node])return;
    mark[node] = true;
    for(auto it : graph[node]){
        if(!mark[it]){
            top_sort(it);
        }
    }
    order.push_back(node);
}
void dfs(int node){
    if(mark[node])return;
    mark[node] = true;
    many++;
    for(auto it : graph[node]){
        if(!mark[it]){
            dfs(it);
        }
    }
}
bool solve(int N, int M){
    int v, w, p;
    //cout<<N<<" "<<M<<endl;
    for(int i=1; i<=N; i++) graph[i].clear();
    for(int i=0; i<M; i++){
        scanf("%d%d%d", &v, &w, &p);
        graph[v].push_back(w);
        //cout<<v<<" "<<w<<" "<<p<<endl;
        if(p==2){
            graph[w].push_back(v);
        }
    }

    order.clear();
    memset(mark, 0, sizeof(mark));
    for(int i=1; i<=N; i++){
        if(mark[i]==false){
            top_sort(i);
        }
    }
    reverse(order.begin(), order.end());
    for(auto it : order){
        memset(mark, 0, sizeof(mark));
        many = 0;
        dfs(it);
        if(many<N) return false;
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int N, M;
    while(scanf("%d%d", &N, &M) && N && M){
        puts(solve(N, M) ? "1" : "0");
    }
}
