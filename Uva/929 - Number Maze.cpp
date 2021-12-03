#include <bits/stdc++.h>
#define LMT 1000
#define MAX INT_MAX
using namespace std;
struct data{
    int x, y, cost;
    inline bool operator <(const data &temp)const {
        return temp.cost<cost;
    }
}now, nxt;

int graph[LMT][LMT], dis[LMT][LMT], N, M;
int row[]={0, 0, -1, 1};
int clm[]={1, -1, 0, 0};

void Dijkstra(); /// this function is small easy.
/// This is same task but different way.
void D(); /// that function is first

int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, J;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%d%d", &N, &M);
        for(i=0; i<N; i++) {
            for(J=0; J<M; J++) {
                scanf("%d", &graph[i][J]);
                dis[i][J] = MAX;
            }
        }
        D();
        printf("%d\n", dis[N-1][M-1]);
    }
    return 0;
}
void Dijkstra() {
    int i, J, vcost, k;
    priority_queue<data>Q;
    dis[0][0] = graph[0][0];
    now.x = 0; now.y = 0;
    now.cost = graph[0][0];
    Q.push(now);
    while(!Q.empty()) {
        now = Q.top(); Q.pop();
        vcost = dis[now.x][now.y];

        for(k=0; k<4; k++) {
            i = now.x+row[k];
            J = now.y+clm[k];
            nxt.cost = vcost+graph[i][J];

            if(dis[i][J]>nxt.cost && (i>=0 && J>=0 && i<N && J<M)) {
                nxt.x = i, nxt.y = J;
                dis[i][J] = nxt.cost;
                Q.push(nxt);
            }
        }
    }
}
void D() {
    int i, J, vcost;
    priority_queue<data>Q;
    dis[0][0] = graph[0][0];
    now.x = 0; now.y = 0;
    now.cost = graph[0][0];
    Q.push(now);
    while(!Q.empty()) {
        now = Q.top(); Q.pop();
        vcost = dis[now.x][now.y];

        i = now.x; J = now.y+1;
        nxt.cost = vcost+graph[i][J];
        if(dis[i][J]>nxt.cost && (i>=0 && J>=0 && i<N && J<M)) {
            nxt.x = i, nxt.y = J; dis[i][J] = nxt.cost;
            Q.push(nxt);
        }
        i = now.x; J = now.y-1;
        nxt.cost = vcost+graph[i][J];
        if(dis[i][J]>nxt.cost && (i>=0 && J>=0 && i<N && J<M)) {
            nxt.x = i, nxt.y = J; dis[i][J] = nxt.cost;
            Q.push(nxt);
        }
        i = now.x+1; J = now.y;
        nxt.cost = vcost+graph[i][J];
        if(dis[i][J]>nxt.cost && (i>=0 && J>=0 && i<N && J<M)) {
            nxt.x = i, nxt.y = J; dis[i][J] = nxt.cost;
            Q.push(nxt);
        }
        i = now.x-1; J = now.y;
        nxt.cost = vcost+graph[i][J];
        if(dis[i][J]>nxt.cost && (i>=0 && J>=0 && i<N && J<M)) {
            nxt.x = i, nxt.y = J; dis[i][J] = nxt.cost;
            Q.push(nxt);
        }
    }
}
