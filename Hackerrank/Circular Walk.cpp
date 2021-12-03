#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define SIZE 10000009

int dis[SIZE], n;
unsigned graph[SIZE];
bool mark[SIZE];
queue<int>Q;

inline void clockw(int x){
    int i=x+1, in=graph[x];
    for(; (in); i++, in--){
        if(i>=n) i=0;
        if(mark[i]==0){
            if(graph[i]) Q.push(i);
            dis[i] = dis[x]+1;
            mark[i]=1;
        }
    }
}
inline void anticlockw(int x){
    int i=x-1, in=graph[x];
    for(; (in); i--, in--){
        if(i<0) i=n-1;
        if(mark[i]==0){
            if(graph[i]) Q.push(i);
            dis[i] = dis[x]+1;
            mark[i]=1;
        }
    }
}
int bfs(int s, int t){
    int x;
    Q.push(s);
    dis[s]=0;
    mark[s]=1;
    while(!Q.empty()){
        x = Q.front(); Q.pop();

        clockw(x);
        if(dis[t]) return dis[t];
        anticlockw(x);
        if(dis[t]) return dis[t];

    }
    return -1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int s, t, i;
    int g, seed, p;
    scanf("%d%d%d", &n, &s, &t);
    scanf("%u%d%d%d", &graph[0], &g, &seed, &p);

    if(s==t) return puts("0"), 0;

    if((graph[0]==0 || g==0) && seed==0)return puts("-1"), 0;
    else if(g==0){
        g = seed%p;
        for(i=1; i<n; graph[i++]=g);
    }
    else{
        for(i=1; i<n; graph[i]=(graph[i-1]*g+seed)%p, i++);
    }
    if(graph[s]==0) return puts("-1"), 0;
    cout<<bfs(s, t)<<endl;

    return 0;
}
