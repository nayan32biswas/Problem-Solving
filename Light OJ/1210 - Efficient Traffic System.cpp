#include <bits/stdc++.h>
using namespace std;
#define Size 20001
typedef pair<int, int> ppi;
vector<int> graph[Size], Rgraph[Size];
vector<ppi> edge;
int mark[Size], inD[Size], outD[Size], compnt;
bool visit[Size];
stack<int>S;
void topSort(int node)
{
    visit[node]=1;
    int len = graph[node].size(), v;
    for(int i=0; i<len; i++){
        v = graph[node][i];
        if(!visit[v]) topSort(v);
    }
    S.push(node);
}
void dfs(int node)
{
    visit[node]=1;
    int len = Rgraph[node].size(), v;
    for(int i=0; i<len; i++){
        v = Rgraph[node][i];
        if(!visit[v]) dfs(v);
    }
    mark[node] = compnt;
}
void SCC(int node)
{
    for(int i=1; i<=node; i++) if(!visit[i]) topSort(i);
    memset(visit, 0, sizeof(visit));
    compnt=0;
    while(!S.empty()){
        int v = S.top(); S.pop();
        if(!visit[v]) dfs(v), compnt++;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, test, node, E, x, y;
    cin>>test;
    for(int t=1; t<=test; t++){
        printf("Case %d: ", t);
        scanf("%d%d", &node, &E);
        if(!E){
            cout<<node<<endl;
            continue;
        }
        for(i=0; i<=node; i++)graph[i].clear(), Rgraph[i].clear();
        edge.clear();
        while(!S.empty()) S.pop();
        memset(mark, -1, sizeof(mark));
        memset(visit, 0, sizeof(visit));
        memset(inD, 0, sizeof(inD));
        memset(outD, 0, sizeof(outD));
        for(i=0; i<E; i++){
            scanf("%d%d", &x, &y);
            edge.push_back(make_pair(x, y));
            graph[x].push_back(y);
            Rgraph[y].push_back(x);
        }
        SCC(node);
        if(compnt==1){puts("0");continue;};
        for(i=0; i<E; i++){
            x = mark[edge[i].first];
            y = mark[edge[i].second];
            if(x!=y) outD[x]++, inD[y]++;
        }
        for(i=0, x=0, y=0; i<compnt; i++){
            if(!inD[i]) x++;
            if(!outD[i]) y++;
        }

        printf("%d\n", max(x, y));
    }
    return 0;
}
