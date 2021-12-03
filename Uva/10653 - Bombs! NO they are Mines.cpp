#include <bits/stdc++.h>
#define SIZ 1009
using namespace std;
/*struct data
{
    int x, y;
    bool operator <(const data& temp)const
    {  return temp.x<=temp.y;  }
}now;*/
bool state[SIZ][SIZ];
int dis[SIZ][SIZ], R, C, dis_R, dis_C, x, y;
int d_R[]={0, 0, -1, 1};
int d_C[]={1, -1, 0, 0};

inline bool finde(int r, int c){
    return r<R && c<C && r>=0 && c>=0 && !state[r][c];
}
//int bfs(data next);
int BFS(int x, int y);
int main()
{
    //freopen("graph.txt", "r", stdin);
    int pos, i, J, n, many, num, ans;
    while(scanf("%d%d", &R, &C)==2 && (R && C)){
        scanf("%d", &many);
        memset(state, 0, sizeof(state));
        for(i=0; i<many; i++){
            scanf("%d%d", &pos, &n);
            for(J=0; J<n; J++){
                scanf("%d", &num);
                state[pos][num]=1;
            }
        }
        scanf("%d%d%d%d", &i, &J, &dis_R, &dis_C);
        ans = BFS(i, J);
        cout<<ans<<endl;
    }
    return 0;
}
int BFS(int x, int y)
{
    memset(dis, 0, sizeof(dis));
    int i, J, k;
    queue<int>Q;
    state[x][y]=1;
    Q.push(x);
    Q.push(y);
    while(!Q.empty()){
        x = Q.front(); Q.pop();
        y = Q.front(); Q.pop();
        for(k=0; k<4; k++){
            i = x+d_R[k];
            J = y+d_C[k];
            if(finde(i, J)){
                state[i][J]=1;
                dis[i][J]=dis[x][y]+1;
                if(state[dis_R][dis_C]==1)return dis[dis_R][dis_C];
                Q.push(i);
                Q.push(J);
            }
        }
    }
    return -1;
}
/*int bfs(data next)
{
    memset(dis, 0, sizeof(dis));
    priority_queue<data>Q;
    state[now.x][now.y]=1;
    Q.push(now);
    while(!Q.empty()){
        now = Q.top(); Q.pop();
        for(int i=0; i<4; i++){
            next.x = (now.x)+d_R[i];
            next.y = (now.y)+d_C[i];
            if(finde(next.x, next.y)){
                state[next.x][next.y]=1;
                dis[next.x][next.y]=dis[now.x][now.y]+1;
                if(state[dis_R][dis_C]==1)return dis[dis_R][dis_C];
                Q.push(next);
            }
        }
    }
    return 0;
}*/
