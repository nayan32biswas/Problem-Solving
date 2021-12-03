#include <bits/stdc++.h>
using namespace std;
#define LMT 150009
vector<int>graph[LMT];
bool vis[LMT];
int len;
bool BFS(int i){
    int len1, J, cou=0;
    vis[i] = 1;
    queue<int>Q;
    Q.push(i);
    while(!Q.empty()){
        i = Q.front(); Q.pop();
        len1 = graph[i].size();
        if(len1!=len || cou>len1){
            return false;
        }
        for(J=0; J<len1; ++J){
            if(!vis[graph[i][J]]){
                vis[graph[i][J]] = 1;
                cou++;
                Q.push(graph[i][J]);
            }
        }
    }
    return true;
}


int main()
{
    int n, m, i, J, x, y;
    scanf("%d%d", &n, &m);
    for(i=0; i<m; i++) {
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool ck=true;
    for(i=1; i<=n; i++){
        if(vis[i]==false) {
            len = graph[i].size();
            if(len>1 && !BFS(i)){
                ck=false;
                break;
            }
        }
    }
    if(ck)puts("YES");
    else puts("NO");
}
