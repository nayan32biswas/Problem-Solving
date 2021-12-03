#include <bits/stdc++.h>
using namespace std;
#define Size 20005
set<int>Set;
vector<int>graph[Size];
bool mark[Size], war[Size];
int bfs(int sorce) {
    int TRUE = 0, FALSE = 1;
    queue<int>Q;
    Q.push(sorce);
    mark[sorce] = true;
    war[sorce] = false;
    while(!Q.empty()) {
        int parents = Q.front();
        Q.pop();
        int it, sss = graph[parents].size();
        for(int i=0; i<sss; i++) {
            it = graph[parents][i];
            if(mark[it]==false) {
                mark[it] = true;
                war[it] = (!war[parents]);
                if(war[it]==1) {
                    TRUE++;
                }
                else{
                    FALSE++;
                }
                Q.push(it);
            }
        }
    }

    return max(TRUE, FALSE);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test, n, u, v, i, Max;
    scanf("%d", &test);

    for(int t=1; t<=test; t++) {
        scanf("%d", &n);
        Max = 0;
        Set.clear();
        for(int i=0; i<Size; i++) {
            graph[i].clear();
        }
        for(i=0; i<n; i++) {
            scanf("%d%d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            Set.insert(u);
            Set.insert(v);
        }
        printf("Case %d: ", t);
        memset(mark, 0, sizeof(mark));
        memset(war, 0, sizeof(war));
        int Max=0;
        for(set<int>::iterator it=Set.begin(); it!=Set.end(); ++it){
            if(mark[*it]==false){
                Max += bfs(*it);
            }
        }
        printf("%d\n", Max);
    }
    return 0;
}
