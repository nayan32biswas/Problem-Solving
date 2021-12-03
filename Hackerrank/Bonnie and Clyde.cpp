#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}
vector<int>graph[100009];
int top_len[100009];
void bfs(int Bonnie , int Clyde , int restaurant, bool *mark){
    int i, len, u, v;
    queue<int>Q;
    Q.push(restaurant);
    mark[restaurant] = true;
    if(graph[restaurant].size()<2) {puts("NO"); return;}
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        len = top_len[u];
        for(i=0; i<len; i++){
            v = graph[u][i];
            if(v==Bonnie || v==Clyde){mark[v]=true;}
            else if(!mark[v]){
                mark[v]=true;
                Q.push(v);
            }
        }
        if(mark[Bonnie] && mark[Clyde]) {puts("YES"); return;}
    }
    puts("NO");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, n, m, q, x, y, to;
    scanf("%d%d%d", &n, &m, &q);
    for(i=0; i<m; i++){
        read(x); read(y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }n++;
    for(i=1; i<n; i++)top_len[i] = graph[i].size();
    bool mark[n];
    for(i=0; i<q; i++){
        memset(mark, 0, sizeof(mark));
        read(x); read(y); read(to);
        bfs(x, y, to, mark);
    }
}
