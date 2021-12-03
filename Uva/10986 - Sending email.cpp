#include <bits/stdc++.h>
#define LMT 20009
#define MAX INT_MAX
using namespace std;
typedef pair<int, int> par;
par no, nx;
int dist[LMT];

int main() {
    //freopen("input.txt", "r", stdin);
    int i, test, n, m, S, T, x, y, w, vcost, len;
    int ans;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d%d%d", &n, &m, &S, &T);
        vector<par>graph[n];
        for(i=0; i<n; dist[i]=MAX, i++);
        while(m--){
            scanf("%d%d%d", &x, &y, &w);
            no.first = y; no.second = w;
            graph[x].push_back(no);
            no.first = x;
            graph[y].push_back(no);
        }
        priority_queue<par>Q;
        no.first = S; no.second=0;
        Q.push(no);
        dist[S]=0;

        while(!Q.empty()) {
            no = Q.top(); Q.pop();
            vcost = dist[no.first];
            len = graph[no.first].size();

            for(i=0; i<len; i++) {
                nx.first = graph[no.first][i].first;
                nx.second = vcost + graph[no.first][i].second;
                if(dist[nx.first]>nx.second) {
                    dist[nx.first] = nx.second;
                    Q.push(nx);
                }
            }
        }

        printf("Case #%d: ", t);
        if(dist[T]==MAX) puts("unreachable");
        else printf("%d\n", dist[T]);
    }
    return 0;
}
