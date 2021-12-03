#include <bits/stdc++.h>
using namespace std;
vector<int>graph[22];
int dis[22], len[22];

int bfs(int node, int to){
    memset(dis, 0, sizeof(dis));
    int next, i;
    queue<int>Q;
    Q.push(node);
    while(!Q.empty()){
        node = Q.front(); Q.pop();
        if(!len[node]) len[node] = graph[node].size();
        for(i=0; i<len[node]; i++){
            next = graph[node][i];
            if(!dis[next]){
                dis[next] = dis[node]+1;
                Q.push(next);
                if(dis[to]) return dis[to];
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int i, j, test, x, y, t=0, ans;
    while(scanf("%d", &test)==1){
        memset(len, 0, sizeof(len));
        for(i=0; i<21; i++) graph[i].clear();

        for(i=0; i<test; i++) {
            scanf("%d", &x);
            graph[1].push_back(x);
            graph[x].push_back(1);
        }
        for(i=2; i<20; i++){
            scanf("%d", &test);
            for(j=0; j<test; j++){
                scanf("%d", &x);
                graph[i].push_back(x);
                graph[x].push_back(i);
            }
        }
        printf("Test Set #%d\n", ++t);
        scanf("%d", &test);
        for(i=0; i<test; i++){
            scanf("%d%d", &x, &y);
            ans = bfs(x, y);
            printf("%2d to %2d: %d\n", x, y, ans);
        }
        puts("");
    }
    return 0;
}
