#include <bits/stdc++.h>
using namespace std;
#define Size 102
typedef pair<int, int> ppi;
int row, clm;
int stage[Size][Size], stage2[Size][Size], total;
ppi prnt[Size][Size], now;
bool ck;
bool check(int x, int y){
    return x>=0 && y>=0 && x<row && y<clm;
}
void bfs(int x, int y, int incre){
    memset(stage2, 0, sizeof(stage2));
    now = make_pair(x, y);
    stage2[0][0]=stage[0][0];
    int value;
    queue<ppi>Q;
    Q.push(now);
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        x = now.first, y = now.second+incre;
        value = stage2[now.first][now.second]+stage[x][y];
        if(check(x, y) && stage2[x][y]<=value){
            stage2[x][y]=value;
            prnt[x][y] = now;
            Q.push(make_pair(x, y));
        }

        x = now.first+incre, y = now.second;
        value = stage2[now.first][now.second]+stage[x][y];
        if(check(x, y) && stage2[x][y]<=value){
            stage2[x][y]=value;
            prnt[x][y] = now;
            Q.push(make_pair(x, y));
        }
    }
    total = stage2[0][0];
    if(ck) return;
    x = row-1, y = clm-1;
    total = stage2[x][y];
    stage[0][0] = stage[x][y]=0;
    int u, v;
    while(prnt[x][y].first!=0 || prnt[x][y].second!=0){
        u = x, v = y;
        x = prnt[u][v].first;
        y = prnt[u][v].second;
        stage[x][y]=0;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, j, ans;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        memset(stage, 0, sizeof(0));
        scanf("%d%d", &row, &clm);
        for(i=0; i<row; i++)for(j=0; j<clm; j++){
            scanf("%d", &stage[i][j]);
        }
        ck=false;
        bfs(0, 0, 1);
        ans = total;
        ck = true;
        bfs(row-1, clm-1, -1);
        printf("%d\n", ans+total);
    }
}
