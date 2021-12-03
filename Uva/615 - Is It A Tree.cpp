#include <bits/stdc++.h>
using namespace std;
#define Size 10000
vector<int>graph[Size];
char mark[Size];
int coun;
bool ck;
map<long long, int>M;
void dfs(int node){
    mark[node]++;
    coun++;
    if(mark[node]>1) ck = true;

    int i, len = graph[node].size();
    for(auto it : graph[node]){
        if(ck) return;
        dfs(it);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test = 0, id=1, root, Max;
    long long x, y;
    while(scanf("%lld%lld", &x, &y) && x>=0 && y>=0) {
        printf("Case %d ", ++test);
        if(!x && !y){
            puts("is a tree.");
            continue;
        }
        M[x] = id++;
        if(!M[y]) M[y] = id++;
        graph[M[x]].push_back(M[y]);
        if(x && y)while(scanf("%lld%lld", &x, &y) && x && y) {
            if(!M[x]) M[x] = id++;
            if(!M[y]) M[y] = id++;
            graph[M[x]].push_back(M[y]);
        }
        root = Max = 0;
        for(int i=1; i<id; i++){
            coun = 0;
            memset(mark, 0, sizeof(mark));
            dfs(i);
            if(ck) break;
            if(coun>Max){
                Max = coun;
                root = i;
            }
        }
        Max++;
        if(Max!=id) ck = true;
        if(ck) puts("is not a tree.");
        else puts("is a tree.");

        for(int i=0; i<id; i++)graph[i].clear();
        M.clear();
        ck = false;
        id = 1;
    }
    return 0;
}
