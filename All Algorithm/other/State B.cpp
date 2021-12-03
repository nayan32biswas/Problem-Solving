#include <bits/stdc++.h>
#define SIZ 111
using namespace std;
struct data{
    int x, y;
    bool operator <(const data& temp)const{return x>temp.x;}
}p, now;
char s[SIZ][SIZ];
bool vis[SIZ][SIZ], ck, ck1, ck2;
int dis[SIZ][SIZ], row, cloum;
void bfs(int i, int J);
int main()
{
    freopen("graph.txt", "r", stdin);
    int test, i, J;
    int saif, saif_i, saif_J;
    int sabi, sabi_i, sabi_J;
    int start, D_i, D_J;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>row>>cloum>>start;
        for(i=0; i<row; i++){
            scanf("%s", s[i]);
        }
        //for(i=0; i<row; i++) printf("%s\n", s[i]);

        for(i=0, ck=0, ck1=0, ck2=0; i<row; i++){
            for(J=0; J<cloum; J++){
                if(ck==0 && s[i][J]=='D'){
                    D_i=i, D_J=J, ck=1;
                }
                else if(ck1==0 && s[i][J]=='1'){
                    saif_i=i, saif_J=J, ck1=1;
                }
                else if(ck2==0 && s[i][J]=='2'){
                    sabi_i=i, sabi_J=J, ck2=1;
                }
            }
            if(ck==1 && ck1==1 && ck2==1)break;
        }
        //cout<<D_i<<' '<<D_J<<endl;
        bfs(D_i, D_J);
        saif = dis[saif_i][saif_J];
        sabi = dis[sabi_i][sabi_J];
        cout<<saif<<' '<<sabi<<endl;
        printf("Case %d: ", t);
        if(saif==0 && sabi==0) puts("IMPOSSIBLE");
        if(sabi>saif) puts("Saif");
        else if(saif>sabi)puts("Sabi");
        else{
            if(start==1)puts("Saif");
            else puts("Sabi");
        }
    }
}
void bfs(int i, int J)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    p.x=i, p.y=J;
    vis[i][J]=1;
    priority_queue<data>Q;
    Q.push(p);
    while(!Q.empty()){
        now = Q.top(); Q.pop();
        p.x=now.x-1, p.y=now.y;
        if(p.x>0 && vis[p.x][p.y]==0 && s[p.x][p.y]!='#'){
            dis[p.x][p.y] = dis[now.x][now.y]+1;
            vis[p.x][p.y]=1;
            Q.push(p);
        }
        p.x=now.x, p.y=now.y-1;
        if(p.y>0 && vis[p.x][p.y]==0 && s[p.x][p.y]!='#'){
            dis[p.x][p.y] = dis[now.x][now.y]+1;
            vis[p.x][p.y]=1;
            Q.push(p);
        }
        p.x=now.x, p.y=now.y+1;
        if(p.y<cloum && vis[p.x][p.y]==0 && s[p.x][p.y]!='#'){
            dis[p.x][p.y] = dis[now.x][now.y]+1;
            vis[p.x][p.y]=1;
            Q.push(p);
        }
        p.x=now.x+1, p.y=now.y;
        if(p.x<row && vis[p.x][p.y]==0 && s[p.x][p.y]!='#'){
            dis[p.x][p.y] = dis[now.x][now.y]+1;
            vis[p.x][p.y]=1;
            Q.push(p);
        }
    }
}
