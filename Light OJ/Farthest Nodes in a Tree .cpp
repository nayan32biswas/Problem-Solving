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
#define INF 1<<30
#define SIZE 30009
typedef pair<int, int> ppi;
ppi MAX, memory;
struct stage {
    long long city, dis;
    bool operator <(const stage& x)const {
        return dis > x.dis;
    }
}Now, Next;
vector<int>graph[SIZE], cost[SIZE];
int destination[SIZE];

void Dijkstra(int node, int n) {
    int i, len, vcost;
    priority_queue<stage>Q;

    for(i=0; i<=n; destination[i++]=INF);
    Now.city = node, Now.dis = 0; destination[node] = 0;
    MAX.first=0, MAX.second=0;
    Q.push(Now);

    while(!Q.empty()) {
        Now = Q.top(); Q.pop();
        vcost = destination[Now.city];
        len = graph[Now.city].size();
        for(i=0; i<len; i++) {
            Next.city = graph[Now.city][i], Next.dis = cost[Now.city][i]+vcost;

            if(destination[Next.city] > Next.dis) {
                destination[Next.city] = Next.dis;
                if(destination[Next.city]>MAX.first){
                    MAX.first = destination[Next.city];
                    MAX.second = Next.city;
                }
                Q.push(Next);
            }
        }
    }
    //for(i=0; i<n; i++) cout<<destination[i]<<' ';cout<<endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, test, n, u, v, w;
    read(test);
    for(int t=1; t<=test; t++){
        read(n);
        for(i=0; i<n; i++){
            graph[i].clear();
            cost[i].clear();
        }
        for(i=1; i<n; i++){
            read(u), read(v), read(w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        Dijkstra(0, n);
        Dijkstra(MAX.second, n);
        printf("Case %d: %d\n", t, MAX.first);
    }
    return 0;
}
