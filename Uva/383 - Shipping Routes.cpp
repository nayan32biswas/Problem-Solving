#include <bits/stdc++.h>
#define LMT 1000
using namespace std;
vector<int>graph[LMT], G;
bool visite[LMT+5];
int dis[LMT+5];

int BFS(int x, int y) {
    int i, len, temp;
    queue<int>Q;
    memset(visite, 0, sizeof(visite));
    memset(dis, 0, sizeof(dis));
    dis[x] = 0;
    Q.push(x);
    while(!Q.empty()) {
        x = Q.front(); Q.pop();
        len = graph[x].size();
        for(i=0; i<len; i++) {
            temp = graph[x][i];
            if(!visite[temp]) {
                visite[temp] = 1;
                dis[temp] = dis[x]+1;
                Q.push(temp);
                if(temp==y) {
                    return dis[y];
                }
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, J, M, N, P, ans, x, y;
    puts("SHIPPING ROUTES OUTPUT\n");
    scanf("%d", &test);
    char s[10], s1[10];
    for(int t=1; t<=test; t++) {
        printf("DATA SET  %d\n\n", t);
        scanf("%d%d%d", &M, &N, &P);
        memset(graph, 0, sizeof(graph));
        G.clear();
        for(i=0; i<M; i++){
            scanf("%s", s);
            x = (s[0]-64) * (s[1]-64);
            G.push_back(x);
        }
        for(i=0; i<N; i++) {
            scanf("%s%s", s, s1);
            x = (s[0]-64) * (s[1]-64);
            y = (s1[0]-64) * (s1[1]-64);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(i=0; i<P; i++) {
            scanf("%d%s%s", &ans, s, s1);
            x = (s[0]-64) * (s[1]-64);
            y = (s1[0]-64) * (s1[1]-64);
            x = BFS(x, y);
            if(x==0) {
                puts("NO SHIPMENT POSSIBLE");
            }
            else {
                printf("$%d\n", ans*x*100);
            }
        }
        puts("");
    }
    puts("END OF OUTPUT");
    return 0;
}
