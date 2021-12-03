#include <bits/stdc++.h>
#define SIZ 100010
#define MAX 1e17
using namespace std;
template <typename T>
void input(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}
typedef pair<long long, long long> ppi;

vector<ppi>V[SIZ];
int parent[SIZ], dastination[SIZ];
long long length[SIZ];

void Dijkstra(int n);

int main() {
    //freopen("input.txt", "r", stdin);
    int x, y, w, n,  m;
    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d%d", &x, &y, &w);
        V[x].push_back(make_pair(y, w));
        V[y].push_back(make_pair(x, w));
    }
    Dijkstra(n);
    if(length[n]==MAX) return puts("-1"), 0;

    int i=0;
    dastination[i++] = n;
    m = parent[n];
    dastination[i++]=m;

    while(m!=1) {
        m = parent[m];
        dastination[i++]=m;
    }

    printf("%d", dastination[--i]);
    for(i--; i>=0; i--) printf(" %d", dastination[i]); puts("");

    return 0;
}


void Dijkstra(int n) {
    priority_queue<ppi>Q;
    long long vcost;
    ppi u;
    int i;
    for(i=0, n+=10; i<n; i++)length[i]=MAX;
    u.first = 1, u.second = 0;
    length[1] = 0;
    Q.push(u);

    while(!Q.empty()) {

        u = Q.top(); Q.pop();
        vcost = length[u.first];
        for(auto x : V[u.first]) {
            x.second+=vcost;
            if(length[x.first] > x.second) {
                length[x.first] = x.second;
                parent[x.first] = u.first;
                Q.push(x);
            }
        }
    }
}
