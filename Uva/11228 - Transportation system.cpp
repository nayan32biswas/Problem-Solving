#include <bits/stdc++.h>
using namespace std;
#define Size 2009
struct data{
    int u, v, w;
    bool operator <(const data &T)const{
        return w<T.w;
    }
};

typedef pair< int, int > ppi;
vector< data >graph;
double roads, railways;
int states;
int check[Size], R;
int distance(int x, int y, int x1, int y1){
    x = fabs( x-x1 );
    y = fabs( y-y1 );
    return x*x + y*y;
}
bool rodes_compleat;
int Find(int r){
    if(check[r]==r) return r;
    return check[r] = Find(check[r]);
}
bool is_true(data temp){
    if(rodes_compleat) return true;
    return !(temp.w>R);
}
void MST(int node){
    railways = roads = 0;
    states = 1;
    for(int i=0; i<node; i++) check[i] = i;
    sort(graph.begin(), graph.end());
    int x, y;
    for(auto it : graph){
        x = Find(it.u);
        y = Find(it.v);
        if(x!=y){
            check[x] = y;
            if(is_true(it)) roads += sqrt(it.w);
            else railways += sqrt(it.w), states++;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, node;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>node>>R;
        R *= R;
        vector< ppi >arr(node);
        graph.clear();
        for(int i=0; i<node; i++) scanf("%d%d", &arr[i].first, &arr[i].second);


        for(int i=0; i<node; i++){
            ppi temp = arr[ i ];
            data T;
            T.u = i;
            for(int j=i+1; j<node; j++){
                T.v = j;
                T.w = distance(temp.first, temp.second, arr[j].first, arr[j].second);
                graph.push_back(T);
            }
        }
        MST(node);
        printf("Case #%d: %d %.lf %.lf\n", t, states, roads, railways);
    }
    return 0;
}
