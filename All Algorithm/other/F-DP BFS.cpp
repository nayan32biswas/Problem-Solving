#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#define TLM 1000050
using namespace std;
bool visit[TLM];
long long dis[TLM];
long long bfs(long long N, long long K);
int main()
{
    //freopen("Input.txt", "r", stdin);
    long long N, K;
    while(scanf("%lld%lld", &N, &K)!=EOF){
        printf("%lld\n", bfs(N, K));
    }
    return 0;
}
long long bfs(long long N, long long K)
{
    long long pos, x, y, z;
    memset(visit,0, sizeof(visit));
    memset(dis, 0, sizeof(dis));
    queue<long long>Q;
    Q.push(N);
    visit[N]=1;
    dis[N]=0;
    while(!Q.empty()){
        pos = Q.front();
        Q.pop();
        x = pos<<1;
        y = pos+1;
        z = pos-1;
        if(x<TLM && !visit[x]){
            dis[x] = dis[pos]+1;
            if(K==x){
                return dis[x];
            }
            Q.push(x);
            visit[x]=1;
        }
        if(y<TLM && !visit[y]){
            dis[y] = dis[pos]+1;
            if(K==y){
                return dis[y];
            }
            Q.push(y);
            visit[y]=1;
        }
        if(z>=0 && !visit[z]){
            dis[z] = dis[pos]+1;
            if(K==z){
                return dis[z];
            }
            Q.push(z);
            visit[z]=1;
        }
    }
    return dis[K];
}
/*#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#define ALT 1000010
using namespace std;
bool visit[ALT];
int dis[ALT];
vector<int>v[ALT];
int BFS(int N, int K);
int main()
{
    //freopen("Input.txt", "r", stdin);
    int N, K;
    while(cin>>N>>K){
        if(N<K)
            cout<<BFS(N, K)<<endl;
        else cout<<N-K<<endl;
    }
    return 0;
}
int BFS(int N, int K)
{
    int pos, siz, temp, x, y, z;
    queue<int>Q;
    memset(visit,0, sizeof(visit));
    memset(dis, 0, sizeof(dis));
    Q.push(N);
    visit[N]=1;
    dis[N]=0;
    while(!Q.empty()){
        pos = Q.front();
        Q.pop();
        x = pos<<1;
        y = pos+1;
        z = pos-1;
        if(x<=K && visit[x]==0)
            v[pos].push_back(x);

        if(y<=K && visit[y]==0)
            v[pos].push_back(y);

        if(z>0 && visit[z]==0)
            v[pos].push_back(z);

        siz=v[pos].size();

        for(int i=0; i<siz; i++) {
            temp = v[pos][i];
            if(!visit[temp]) {
                visit[temp]=1;
                Q.push(temp);
                dis[temp] = dis[pos]+1;
                if(temp==K)
                    return dis[temp];
            }
        }
    }
    return dis[K];
}
*/
