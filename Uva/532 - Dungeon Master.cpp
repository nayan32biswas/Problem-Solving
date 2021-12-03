#include <bits/stdc++.h>
using namespace std;
struct data{
    int x, y, z;
}Now, Escaped;
int L, R, C;
char str[31][31][31];
int dis[31][31][31];
bool Check(data pos){
    if(str[pos.z][pos.x][pos.y]=='#') return false;
    if(pos.x<0 || pos.y<0 || pos.z<0 || pos.x>=R || pos.y>=C || pos.z>=L) return false;
    return true;
}
void BFS(){
    int i, j, DIS;
    queue<data>Q;
    memset(dis, 0, sizeof(dis));
    Q.push(Now);
    while(!Q.empty()){
        Now = Q.front(); Q.pop();
        DIS = dis[Now.z][Now.x][Now.y];
        Now.y++;
        if(Check(Now)){
            str[Now.z][Now.x][Now.y]='#';
            dis[Now.z][Now.x][Now.y]=DIS+1;
            Q.push(Now);
        }Now.y-=2;
        if(Check(Now)){
            str[Now.z][Now.x][Now.y]='#';
            dis[Now.z][Now.x][Now.y]=DIS+1;
            Q.push(Now);
        }Now.y++;
        Now.x++;
        if(Check(Now)){
            str[Now.z][Now.x][Now.y]='#';
            dis[Now.z][Now.x][Now.y]=DIS+1;
            Q.push(Now);
        }Now.x-=2;
        if(Check(Now)){
            str[Now.z][Now.x][Now.y]='#';
            dis[Now.z][Now.x][Now.y]=DIS+1;
            Q.push(Now);
        }Now.x++;
        Now.z++;
        if(Check(Now)){
            str[Now.z][Now.x][Now.y]='#';
            dis[Now.z][Now.x][Now.y]=DIS+1;
            Q.push(Now);
        }Now.z-=2;
        if(Check(Now)){
            str[Now.z][Now.x][Now.y]='#';
            dis[Now.z][Now.x][Now.y]=DIS+1;
            Q.push(Now);
        }
        if(dis[Escaped.z][Escaped.x][Escaped.y]){
            printf("Escaped in %d minute(s).\n", dis[Escaped.z][Escaped.x][Escaped.y]);
            return;
        }
    }
    puts("Trapped!");
}
int main(){
    bool S, E;
    int i, j, k;
    while(scanf("%d%d%d", &L, &R, &C)!=EOF&&(L && R && C)){

        for(i=0, S=true, E=true; i<L; i++){
            for(j=0; j<R; j++){
                scanf("%s", str[i][j]);
                if(S || E){
                    for(k=0; k<C; k++){
                        if(str[i][j][k]=='S') Now.z=i, Now.x=j, Now.y=k, str[i][j][k]='#', S=false;
                        else if(str[i][j][k]=='E') Escaped.z=i, Escaped.x=j, Escaped.y=k, E=false;
                    }
                }
            }
        }
        BFS();
    }
}
