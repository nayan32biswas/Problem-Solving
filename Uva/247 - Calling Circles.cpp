#include <bits/stdc++.h>
using namespace std;
#define Size 30
void Clear(vector<int>G[], int len){
    for(int i=0; i<28; i++) G[i].clear();
}
map<string, int> to_int;
map<int, string> to_str;
vector<int>graph[Size], graphRev[Size], cmp[Size];
stack<int> Stack;
bool mark[Size];
int many;

void dfs(int node){
    mark[node] = 1;
    for(auto v : graph[node])if(!mark[v]) dfs(v);
    Stack.push(node);
}
void dfs1(int node){
    mark[node] = 1;
    for(auto v : graphRev[node])if(!mark[v]) dfs1(v);
    cmp[many].push_back(node);
}
void rev(vector<int> G[], int len){
    for(int i=1; i<=len; i++)for(auto x : graph[i])G[x].push_back(i);
}
void SORT(){
    for(int i=0; i<many; i++)sort(cmp[i].begin(), cmp[i].end());
    for(int i=0; i<many-1; i++)
        for(int j=i+1; j<many; j++)
            if(cmp[i][0]>cmp[j][0])swap(cmp[i], cmp[j]);
}
void SCC(int node){
    memset(mark, 0, sizeof(mark));
    while(!Stack.empty())Stack.pop();
    for(int i=1; i<=node; i++)if(!mark[i]) dfs(i);

    Clear(graphRev, node);
    Clear(cmp, node);

    rev(graphRev, node);
    memset(mark, 0, sizeof(mark));
    many=0;

    while(!Stack.empty()){
        if(!mark[Stack.top()]) dfs1(Stack.top()), many++;
        Stack.pop();
    }
    SORT();
    bool ck;
    for(int i=0, j=0; i<many; i++, j=0){
        ck=false;
        for(auto x : cmp[i]){
            if(j) printf(", "); j++;
            cout<<to_str[x];
            ck=true;
        }
        if(ck)cout<<endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int node, edge, test=0, i;
    while(scanf("%d%d", &node, &edge)==2 && (node || edge)){
        Clear(graph, node);
        to_int.clear(); to_str.clear();

        string u, v;
        i=1;
        while(edge--){
            cin>>u>>v;
            if(to_int[u]==0) {to_int[u] = i, to_str[i++]=u;}
            if(to_int[v]==0) {to_int[v] = i, to_str[i++]=v;}
            graph[to_int[u]].push_back(to_int[v]);
        }
        if(test) puts("");
        printf("Calling circles for data set %d:\n", ++test);
        SCC(node);
    }
}
