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

struct Graph{
    int x, y, w;
    bool operator <(const Graph& p)const{return w>p.w;}
}Get;
int check[100010];
long long sum, way;
vector<Graph>V;

inline int Find(int r){
    if(check[r]==r) return r;
    else check[r] = Find(check[r]);
    return check[r];
}
void MST(int node) {

    int i, len, coun=0, x, y;

    sort(V.begin(), V.end());
    for(i=0; i<=node;  check[i]=i, i++);

    for(i=0, len=V.size(); i<len; i++) {
        x = Find(V[i].x);
        y = Find(V[i].y);
        if(x!=y){
            sum+=V[i].w;
            check[x]=y;
            coun++;
            way++;
            if(coun==node) break;
        }
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    int x, y, w, edge, node, t, test;
    scanf("%d", &test);
    for(t=1; t<=test; t++){
        way = 0, sum = 0;
        V.clear();
        scanf("%d%d", &node, &edge);
        while(edge--){
            read(Get.x); read(Get.y); read(Get.w);
            V.push_back(Get);
        }
        MST(node);
        printf("Case %d: %lld %lld\n", t, way, sum);
    }
    return 0;
}
