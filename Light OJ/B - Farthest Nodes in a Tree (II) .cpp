#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
#define INF 1<<30
#define SIZE 30009
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
ppi MAX, Now, Next;
vector<ppi>graph[SIZE];
int n;

void BFS(int node, int *distanc) {
    int i, len, vcost;
    queue<ppi>Q;
    Now.first = node, Now.second = 0; distanc[node] = 0;
    MAX.first=0, MAX.second=0;
    Q.push(Now);
    while(!Q.empty()) {
        Now = Q.front(); Q.pop();
        vcost = distanc[Now.first];
        len = graph[Now.first].size();
        for(i=0; i<len; i++) {
            Next.first = graph[Now.first][i].first;
            Next.second = graph[Now.first][i].second+vcost;
            if(distanc[Next.first]==-1) {
                distanc[Next.first] = Next.second;
                if(distanc[Next.first]>MAX.first){
                    MAX.first = distanc[Next.first];
                    MAX.second = Next.first;
                }
                Q.push(Next);
            }
        }
    }
    //for(i=0; i<n; i++) printf("%4d", distanc[i]);printf("\t%4d%4d\n", MAX.first, MAX.second);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, test, u, v;
    read(test);
    for(int t=1; t<=test; t++){
        read(n);
        for(i=0; i<=n; graph[i].clear(), i++);

        for(i=1; i<n; i++){
            read(u), read(v), read(Now.second);
            Now.first = v;
            graph[u].push_back(Now);
            Now.first = u;
            graph[v].push_back(Now);
        }
        int distanc[n], distanc1[n];
        printf("Case %d:\n", t);
        memset(distanc, -1, sizeof(distanc));
        BFS(0, distanc);

        memset(distanc, -1, sizeof(distanc));
        BFS(MAX.second, distanc);

        memset(distanc1, -1, sizeof(distanc1));
        BFS(MAX.second, distanc1);

        for(i=0; i<n; i++){
            printf("%d\n", max(distanc[i], distanc1[i]));
        }
    }
    return 0;
}
