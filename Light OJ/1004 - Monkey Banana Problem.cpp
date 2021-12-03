#include <bits/stdc++.h>
using namespace std;
#define Size 200
typedef pair<int, int> ppi;
int graph[Size][105];
int ans[Size][105];
ppi now, past;
void print(int arr[][105], int N){
    for(int i=0; i<(N*2)-1; i++){
        for(int j=0; j<N; j++) printf("%3d", arr[i][j]);
        puts("");
    }
    puts("");
}
int bfs(int N){
    int x, y, value;
    queue<ppi>Q;
    Q.push(make_pair(0, 0));
    ans[0][0] = graph[0][0];
    N--;
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        x = now.first+1;
        y = now.second+1;
        if(now.first>=N) y = now.second-1;
        if(y>=0 && graph[x][y]>0){
            value = graph[x][y]+ans[now.first][now.second];
            if(ans[x][y]<value){
                ans[x][y] = value;
                Q.push(make_pair(x, y));
            }
        }
        x = now.first+1;
        y = now.second;
        if(graph[x][y]>0){
            value = graph[x][y]+ans[now.first][now.second];
            if(ans[x][y]<value){
                ans[x][y] = value;
                Q.push(make_pair(x, y));
            }
        }
    }
    N++;
    return ans[(N*2)-2][0];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, N, dis, i, j, x;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        memset(graph, 0, sizeof(graph));
        memset(ans, 0, sizeof(ans));
        scanf("%d", &N);
        for(i=0; i<(N-1); i++){
            for(j=0; j<=i; j++) scanf("%d", &graph[i][j]);
        }
        for(j=0; j<N; j++) scanf("%d", &graph[i][j]);
        for(i++, x=0; x<(N-1); i++, x++){
            for(j=0; j<(N-x)-1; j++)
                scanf("%d", &graph[i][j]);
        }
        printf("Case %d: %d\n", t, bfs(N));
    }
}
