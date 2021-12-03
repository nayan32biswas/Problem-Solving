#include <bits/stdc++.h>
using namespace std;
map<string, vector<string> > graph;
map<string, int>vis;
map<string, bool>mark;
bool check;
void dfs(string sorce){
    int i, len;
    if(check) return;
    vis[sorce]=1;
    len = graph[sorce].size();
    for(i=0; i<len; i++){
        string node = graph[sorce][i];
        if(vis[node]==1) {check=true; return;}
        if(!vis[node]) dfs(node);
    }
    vis[sorce]=2;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string a, b;
    int test, i, m;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d", &m);
        graph.clear();
        vis.clear();
        mark.clear();
        while(m--){
            cin>>a>>b;
            graph[a].push_back(b);
            mark[a]=true; mark[b]=true;
        }
        map<string, bool>::iterator it;

        check = false;
        printf("Case %d: ", t);
        for(it=mark.begin(); it!=mark.end(); it++){
            if(mark[it->first]==true)dfs(it->first);
            if(check){puts("No"); break;}

        }
        if(!check) puts("Yes");
    }
    return 0;
}
