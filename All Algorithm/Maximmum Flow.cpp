#include <bits/stdc++.h>
using namespace std;
#define INF 1<<20
typedef pair<int, int> ppi;
ppi node;
vector<ppi>graph[10];
int dis[10], parents[10];
void maxflow(int sorce, int to){
    int i, Max, len, Now, Next;
    memset(dis, 0, sizeof(dis));
    dis[sorce]=INF;
    queue<int>Q;
    parents[sorce]=sorce;
    Q.push(sorce);
    while(!Q.empty()){
        Now = Q.front(); Q.pop(); len = graph[Now].size();
        for(i=0; i<len; i++){
            Max = min(dis[Now], graph[Now][i].second); Next = graph[Now][i].first;
            if(dis[Next]<Max){
                dis[Next] = Max;
                parents[Next] = Now;
                Q.push(Next);
            }
        }
    }
    i = parents[to]; cout<<to<<' '<<i<<' ';
    while(i!=sorce){i = parents[i];cout<<i<<' ';}puts("");
}
int main()
{
    freopen("input.txt", "r", stdin);
    int i, x, y, w, n, m, sorce, to;
    cin>>n>>m;
    for(i=0; i<m; i++){
        cin>>x>>y>>w;
        node.first=y, node.second=w;
        graph[x].push_back(node);
    }
    cin>>sorce>>to;
    maxflow(sorce, to);
}
