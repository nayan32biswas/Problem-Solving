#include <bits/stdc++.h>
using namespace std;
struct data{
    int x, y, w;
    bool operator <(const data &T){
        return w<T.w;
    }
};
vector<data>mst;
int mark[1009], n, m;
int Find(int r){
    if(mark[r]==r) return r;
    return mark[r] = Find(mark[r]);
}
void MST(){
    for(int i=0; i<n; i++) mark[i] = i;
    sort(mst.begin(), mst.end());
    int t = 0;
    for(auto V : mst){
        int x = Find(V.x);
        int y = Find(V.y);
        if(x!=y){
            mark[x] = y;
        }
        else {
            if(t) printf(" ");
            t++;
            printf("%d", V.w);
        }
    }
    if(!t) puts("forest");
    else puts("");
}
int main()
{
    while(cin>>n>>m && n && m){
        data v;
        mst.clear();
        for(int i=0; i<m; i++){
            scanf("%d%d%d", &v.x, &v.y, &v.w);
            mst.push_back(v);
        }
        MST();
    }
}
