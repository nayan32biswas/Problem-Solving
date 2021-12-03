#include <bits/stdc++.h>
#define SIZ 111
using namespace std;
bool visit[SIZ];
vector<int>ans, V[SIZ];
void TSort(int node) {
    if(!visit[node]){
        int i, len = V[node].size();
        for(i=0; i<len; i++){
            TSort(V[node][i]);
        }
        visit[node]=1;
        ans.push_back(node);
    }
}
int main()
{
    //freopen("graph.txt", "r", stdin);
    int i, x, y, node, edge, len;
    while(cin>>node>>edge){
        if(!node && !edge) break;
        ans.clear();
        memset(visit, 0, sizeof(visit));
        memset(V, 0, sizeof(V));
        while(edge--){
            scanf("%d%d", &x, &y);
            V[x].push_back(y);
        }
        for(i=1; i<=node; i++){
            TSort(i);
        }
        reverse(ans.begin(), ans.end());
        for(i=0, len=ans.size(); i<len; i++){
            if(i) cout<<' ';
            printf("%d", ans[i]);
        }puts("");
    }
    return 0;
}
