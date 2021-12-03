#include <bits/stdc++.h>
using namespace std;
#define Size 2500
vector<int>graph[Size];
int visit[Size];
void BFS(int source){
    memset(visit, 0, sizeof(visit));
    visit[source] = 1;
    map<int, int>MM;
    queue<int>Que;
    Que.push(source);
    while(!Que.empty()){
        int now = Que.front();
        Que.pop();
        for(auto it : graph[now]){
            if(visit[it]==0){
                visit[it] = visit[now]+1;
                MM[visit[it]]++;
                Que.push(it);
            }
        }
        //puts("");
    }
    int Max=0, maxDay;
    for(auto it : MM){
        if(it.second>Max){
            Max = it.second;
            maxDay = it.first;
        }
    }
    printf("%d %d\n", Max, --maxDay);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int E, N, x;
    scanf("%d", &E);
    for(int i=0; i<E; i++){
        scanf("%d", &N);
        for(int j=0; j<N; j++){
            scanf("%d", &x);
            graph[i].push_back(x);
        }
    }
    int T, source;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &source);
        if(graph[source].size()==0){
            puts("0");
        }
        else{
            BFS(source);
        }
    }
}
