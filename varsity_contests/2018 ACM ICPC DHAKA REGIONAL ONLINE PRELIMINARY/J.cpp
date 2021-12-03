#include <bits/stdc++.h>
using namespace std;
#define Size 200005
int dis[Size], parents[Size];
bool mark[Size];
vector<int>graph[Size];
void bfs(int source) {
    queue<int>Que;
    mark[source] = true;
    Que.push(source);
    while(!Que.empty()) {
        int current = Que.front();
        Que.pop();
        for(auto itr : graph[current]) {
            if(mark[itr]==false) {
                mark[itr] = true;
                parents[itr] = current;
                dis[itr] = dis[current]+1;
                Que.push(itr);
            }
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test, x, y, node;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%d", &node);
        for(int i=0; i<=node; i++)
            graph[i].clear();
        for(int i=1; i<node; i++) {
            scanf("%d%d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        memset(mark, false, sizeof(mark));
        memset(dis, 0, sizeof(dis));
        memset(parents, 0, sizeof(parents));
        bfs(1);
        printf("Case %d:\n", t);
        for(int i=2; i<=node; i++){

            if(dis[i]%2==1){
                printf("%d %d\n", parents[i], i);
            }
            else{
                printf("%d %d\n", i, parents[i]);
            }
        }
    }
}
