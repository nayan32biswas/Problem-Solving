#include <bits/stdc++.h>
using namespace std;

pair<int, int>now, nxt;
int row, clm, k;
char str[505][505];
int dis[505][505];

void print(){
    for(int i=0; i<row; i++){
        for(int j=0; j<clm; j++)printf("%3d", dis[i][j]);
        puts("");
    }
    puts("\n");
}

int R[]={0, 0, 1, -1};
int C[]={1, -1, 0, 0};
inline bool check(int i, int j){
    if(i<0 || j<0 || i==row || j==clm) return false;
    if(str[i][j]!='.' || dis[i][j]>0) return false;
    return true;
}

int bfs(){
    int i, x, y;
    now.first=0, now.second=0;
    queue< pair<int, int> >Q;
    Q.push(now);
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        for(i=0; i<4; i++){
            x = now.first+R[i]; y = now.second+C[i];
            if(check(x, y)==true){
                dis[x][y] = dis[now.first][now.second]+1;
                nxt.first=x, nxt.second=y;
                Q.push(nxt);
            }
        }
        if(dis[row-1][clm-1]) return dis[row-1][clm-1];
    }
    return -1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int start=clock();
    int i, j, they, me;
    scanf("%d%d%d", &row, &clm, &k);
    for(i=0; i<row; i++) scanf("%s", str[i]);

    they = bfs();
    //print();

    while(k--){
        scanf("%d%d", &i, &j);
        str[i][j]='.';
    }

    memset(dis, 0, sizeof(dis));
    me = bfs();
    //print();
    printf("%d\n",clock()-start);
    if(they==-1 && me!=-1) return puts("YES"), 0;
    if(me==-1) return puts("NO"), 0;
    they-=5;
    if(me<they)puts("YES");
    else puts("NO");

    return 0;
}
