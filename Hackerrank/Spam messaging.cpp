#include <bits/stdc++.h>
using namespace std;
#define Size 50005
bool mark[Size];
vector<int>graph[Size];
int len, ans, Max;
void dfs(int node){
    mark[node] = 1;
    len++;
    for(auto it : graph[node]){
        if(!mark[it])dfs(it);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, N, u, v;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d", &N);
        for(int i=1; i<=N; i++) graph[i].clear();
        for(int i=0; i<N; i++){
            scanf("%d%d", &u, &v);
            graph[u].push_back(v);
        }
        Max = ans = 0;
        for(int i=1; i<=N; i++){
            memset(mark, 0, sizeof(mark));
            len = 0;
            dfs(i);
            if(len>Max){
                Max = len;
                ans = i;
            }

        }
        printf("Case %d: %d\n", t, ans);
    }
}
