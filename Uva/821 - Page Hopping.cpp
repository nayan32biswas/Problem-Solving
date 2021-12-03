#include <bits/stdc++.h>
#define SIZE 105
using namespace std;
vector<int>graph[SIZE];
bool visite[SIZE], mark[SIZE];
int dis[SIZE], many, ans;

void bfs(int sorce){
    memset(visite, 0, sizeof(visite));
    memset(dis, 0, sizeof(dis));
    int past, now, len, i;
    queue<int>Q;
    Q.push(sorce);
    visite[sorce]=1;
    while(!Q.empty()){
        past = Q.front(); Q.pop();
        len = graph[past].size();
        for(i=0; i<len; i++){
            now = graph[past][i];
            if(visite[now]==0){
                visite[now]=1;
                dis[now] = dis[past]+1;
                Q.push(now);
                ans+=dis[now];
                many++;
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, i, test=1;
    bool ck=true;
    double temp;
    while(true){
        ck = false;
        for(i=0; i<101; i++) graph[i].clear();
        memset(mark, 0, sizeof(mark));
        many = 0, ans = 0;
        while(scanf("%d%d", &x, &y) && (x && y)){
            graph[x].push_back(y);
            mark[x] = 1;
        }
        for(i=1; i<101; i++)if(mark[i]){
            bfs(i);
            ck = true;
        }
        if(!ck) return 0;
        temp = ((double)ans/many);
        printf("Case %d: average length between pages = ", test++);
        printf("%.3lf", (double)temp);
        puts(" clicks");
    }
}
