#include <bits/stdc++.h>
using namespace std;
struct data{
    int node, dis;
    bool operator <(const data &T)const{
        return T.dis>dis;
    }
}now, temp;
vector<data>graph[100];
int mark[100];
int max_flow(int sorce, int dasti){
    memset(mark, 0, sizeof(mark));
    priority_queue<data>Q;
    int coun = 0;
    now.node = sorce, now.dis = INT_MAX;
    Q.push(now);
    mark[sorce] = INT_MAX;
    while(!Q.empty()){
        now = Q.top();Q.pop();
        sorce = now.node;
        for(auto v : graph[sorce]){
            if(mark[v.node]<mark[sorce]){
                temp.dis = mark[v.node] = max(min(mark[sorce], v.dis), mark[v.node]);
                temp.node = v.node;
                Q.push(temp);
                coun++;
            }
        }
    }
    return mark[dasti];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int N, R, x, y, w, ans, t=0;
    while(scanf("%d%d", &N, &R) && N && R){
        printf("Scenario #%d\nMinimum Number of Trips = ", ++t);
        for(int i=0; i<N; i++) graph[i].clear();
        for(int i=0; i<R; i++){
            scanf("%d%d%d", &x, &y, &now.dis);
            x--, y--;
            now.node = y;
            graph[x].push_back(now);
            now.node = x;
            graph[y].push_back(now);
        }
        scanf("%d%d%d", &N, &R, &w);
        if(N==R){
            puts("0\n");
            continue;
        }
        N--, R--;
        N = max_flow(N, R);
        printf("%d\n", (w+N-2)/(N-1));
        puts("");
    }
}
