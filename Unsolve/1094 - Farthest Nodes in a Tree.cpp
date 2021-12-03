#include <bits/stdc++.h>
#define MAX 999999999999999
using namespace std;
vector<int>V[30010], cost[30010];
long long length[40000], Max, Max1;
struct data{
    long long dis, city;
    bool operator <(const data& x)const{
        return dis>x.dis;
    }
}x, y;
void Dijsktra(int nod);
int main()
{
    freopen("input.txt", "r", stdin);
    int test, n, u, v, w, i, temp;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d", &n);
        if(t!=1){
            Max = 0, Max1 = 0;
            memset(V, 0, sizeof(V));
            memset(cost, 0, sizeof(cost));
            memset(length, 0, sizeof(length));
        }
        temp = n-1;
        while(temp--){
            scanf("%d%d%d", &u, &v, &w);
            V[u].push_back(v);
            V[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        Dijsktra(n);
        for(i=0; i<n; i++){
            if(length[i]>Max){
                if(Max>Max1){
                    Max1 = Max;
                }
                Max = length[i];
            }
        }
        cout<<Max+Max1<<endl;
    }

    return 0;
}
void Dijsktra(int nod)
{
    priority_queue<data>Q;
    int i, J, vcost, len;
    nod+=5;
    for(i=0; i<nod; i++) length[i]=MAX;
    x.dis = 0, x.city = 0;
    length[0] = 0;
    Q.push(x);
    while(!Q.empty()) {
        x = Q.top(); Q.pop();
        vcost = x.dis;
        len = V[x.city].size();
        for(i=0; i<len; i++){
            y.city = V[x.city][i]; y.dis = vcost + cost[x.city][i];
            if(length[y.city]>y.dis) {
                length[y.city] = y.dis;
                Q.push(y);
            }
        }
    }
}
