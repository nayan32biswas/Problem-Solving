#include <bits/stdc++.h>
#define LMT 500009
using namespace std;
vector<int>graph[LMT];
int visite[LMT];
int bfs(int node) {
    int i, len, v, x=1;
    queue<int>Q;
    bool ck;
    visite[node] = 1;
    Q.push(node);
    while(!Q.empty()) {
        node = Q.front(); Q.pop();
        len = graph[node].size();
        for(i=0, ck=false; i<len; i++){
            v = graph[node][i];
            if(!visite[v]) {
                visite[v] = 1;
                Q.push(v);
                ck = true;
            }
        }
        if(ck) x++;
    }
    return x;
}
int main()
{
    int n, u, v, i, ans=0;
    cin>>n;
    for(i=1; i<n; i++) {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(i=1; i<=n; i++){
        if(!visite[i]) ans = max(ans, bfs(i));
    }
    cout<<ans<<endl;
}
