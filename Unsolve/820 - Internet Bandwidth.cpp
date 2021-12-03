#include <bits/stdc++.h>
using namespace std;
#define MAX INT_MAX
#define Size 1000
typedef pair<int, int> ppi;

struct data {
    int first, second;
    bool operator <(const data &T) const{
        return second>T.second;
    }
}now;
vector< data >graph[Size];

int mark[Size], N;
int flow(int s, int t) {
    if(s==t) return 0;
    for(int i=0; i<N; i++) mark[i] = MAX;
    priority_queue< data >Q;

    now.first = s, now.second = 0;

    Q.push(now);
    mark[s] = 0;

    while(!Q.empty()) {
        now = Q.top(); Q.pop();
        for(auto it : graph[now.first]) {
            it.second += now.second;
            if(it.second<mark[it.first]) {
                mark[it.first] = it.second;
                Q.push(it);
            }
        }
    }
    return mark[t];
}
int main() {
    freopen("input.txt", "r", stdin);
    int s, t, c, test=0,  x, y;
    while(cin>>N && N) {
        scanf("%d%d%d", &s, &t, &c);
        for(int i=0; i<c; i++) graph[i].clear();
        s--, t--;
        for(int i=0; i<c; i++) {
            scanf("%d%d%d", &x, &y, &now.second);
            x--, y--;
            now.first = y;
            graph[x].push_back(now);
            now.first = x;
            graph[y].push_back(now);
        }
        if(test) puts("");
        printf("Network %d\n", ++test);
        printf("The bandwidth is %d.\n", flow(s, t));
    }
    return 0;
}
