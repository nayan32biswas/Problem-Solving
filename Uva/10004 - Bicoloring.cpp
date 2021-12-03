#include <bits/stdc++.h>
using namespace std;
#define LMT 209
vector<int>graph[LMT];
bool vis[LMT];

void BFS(int node) {
   int color[LMT]={0}, len, i, V;
   queue<int>Q;
   Q.push(node);
   color[node] = 1;
   vis[node] = 1;
   while(!Q.empty()) {
      node = Q.front(); Q.pop();
      len = graph[node].size();

      for(i = 0; i<len; i++) {
         V = graph[node][i];
         if(!vis[V]) {
            color[V] = color[node]*(-1);
            vis[V] = 1;
            Q.push(V);
         }
         else if(color[V] == color[node]) {
            puts("NOT BICOLORABLE.");
            return;
         }
      }
   }
   puts("BICOLORABLE.");
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, i, x, y;
    while(scanf("%d", &n)==1 && n){
        scanf("%d", &m);

        memset(graph, 0, sizeof(graph));
        memset(vis, 0, sizeof(vis));
        for(i=0; i<m; i++) {
            scanf("%d%d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        BFS(0);
    }
    return 0;
}
