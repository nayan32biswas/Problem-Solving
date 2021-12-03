#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
struct PAIR {
    int wate, node;
}temp;

vector<PAIR>graph[509];
int dis[509];
bool ck[509][509];

void bfs(int n, int sorce){
    int i, len, Now, Next, Max;
    queue<int>Q;
    for(i=0; i<n; dis[i++]=INF);
    dis[sorce]=0;

    Q.push(sorce);
    while(!Q.empty()){
        Now = Q.front(), Q.pop();
        //cout<<Now<<endl;
        for(i=0, len = graph[Now].size(); i<len; i++){

            Next = graph[Now][i].node;
            Max = max(dis[Now], graph[Now][i].wate);
            if(dis[Next]>Max){
                dis[Next] = Max;
                //cout<<Now<<' '<<Next<<' '<<dis[Now]<<' '<<graph[Now][i].wate<<endl;
                Q.push(Next);
            }
        }
    }

    for(i=0; i<n; i++){
        if(dis[i]==INF) puts("Impossible");
        else printf("%d\n", dis[i]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, n, m, x, y, w, test, len;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d", &n, &m);
        memset(ck, false, sizeof(ck));
        for(i=0; i<n; graph[i].clear(), i++);
        while(m--){
            scanf("%d%d%d", &x, &y, &w);
            if(ck[x][y]){
                for(i=0; graph[x][i].node!=y; i++);
                if(graph[x][i].wate>w) graph[x][i].wate=w;
            } else{
                temp.node=y, temp.wate=w;
                graph[x].push_back(temp);
                ck[x][y]=true;
            }

            if(ck[y][x]){
                for(i=0; graph[y][i].node!=x; i++);
                if(graph[y][i].wate>w) graph[y][i].wate=w;
            } else{
                temp.node=x, temp.wate=w;
                graph[y].push_back(temp);
                ck[y][x]=true;
            }

        }
        scanf("%d", &m);
        printf("Case %d:\n", t);
        bfs(n, m);
    }
}

