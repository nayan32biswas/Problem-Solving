#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define Size 40009
#define Max 1e9+999
struct data {
    int x, y, w;
    bool operator <(const data& p)const {
        return w > p.w;
    }
};
int check[Size], wate[Size];
vector<data>graph;
vector< pair<int, int> >tree[Size];
int Find(int r) {
    if(check[r]==r) return r;
    else check[r] = Find(check[r]);
    return check[r];
}
void karuskal(int node) {

    int coun=0, x, y;
    sort(graph.begin(), graph.end());
    for(int i=0; i<=node;  check[i]=i, i++);

    for(auto now : graph) {
        x = Find(now.x);
        y = Find(now.y);
        if(x!=y) {
            check[x]=y;
            coun++;

            tree[now.x].push_back(make_pair(now.y, now.w));
            tree[now.y].push_back(make_pair(now.x, now.w));

            if(coun==node) break;
        }
    }
}
void bfs(){
    pair< int, int> parents;
    memset(wate, 0, sizeof(wate));
    queue< pair<int, int> >Q;
    Q.push(make_pair(0, Max));
    wate[0]=Max;
    while(!Q.empty()){
        parents = Q.front();
        Q.pop();
        for(auto now : tree[parents.first]){
            if(!wate[now.first]){
                wate[now.first] = min(parents.second, now.second);
                Q.push(now);
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, N, E, Q, C, x, y, w, ans;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d", &N, &E);
        data now;
        graph.clear();
        for(int i=0; i<N; i++) tree[i].clear();
        for(int i=0; i<E; i++){
            scanf("%d%d%d", &now.x, &now.y, &now.w);
            now.x--, now.y--;
            graph.push_back(now);
        }
        karuskal(N);
        bfs();
        vector<int>temp;
        for(int i=1; i<N; i++)if(wate[i]>0){
            temp.push_back(wate[i]);
        }
        sort(temp.begin(), temp.end());
        N = temp.size();

        printf("Case %d:\n", t);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d", &C);
            printf("%d\n", N - ( ( lower_bound(temp.begin(), temp.end(), C) )-temp.begin() ) );
        }
    }
    return 0;
}
