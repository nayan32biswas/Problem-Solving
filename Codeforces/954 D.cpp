#include <bits/stdc++.h>
using namespace std;
#define Size 1001

vector<int>graph[Size];
int fromS[Size], fromT[Size];
bool mark[Size][Size];

int bfs(int dis[], int start){
    queue<int>Q;
    Q.push(start);
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(auto it : graph[now]){
            if(it!=start && !dis[it]){
                dis[it] = dis[now]+1;
                Q.push(it);
            }
        }
    }
}

int main()
{
    int n, m, s, t, x, y, Min, ans=0;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=0; i<m; i++){
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
        mark[x][y] = 1;
        mark[y][x] = 1;
    }
    bfs(fromS, s);
    Min = fromS[t];
    bfs(fromT, t);
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++)if(!mark[i][j]){
            if((fromS[i]+fromT[j]+1)>=Min && fromS[j]+fromT[i]+1>=Min){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
