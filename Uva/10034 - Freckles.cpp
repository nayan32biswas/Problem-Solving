#include <bits/stdc++.h>
using namespace std;
double pitha(double x, double x1, double y, double y1){
    return sqrt(pow(abs(x-x1), 2)+pow(abs(y-y1), 2));
}
struct data{
    int x, y;
    double w;
    bool operator <(const data &T)const{
        return w<T.w;
    }
};
vector<data>mst;
int mark[109], n;
int Find(int r){
    if(mark[r]==r) return r;
    return mark[r] = Find(mark[r]);
}
void MST(){
    for(int i=0; i<104; i++) mark[i] = i;
    sort(mst.begin(), mst.end());
    int x, y;
    double sum = 0;
    for(auto V : mst){
        x = Find(V.x);
        y = Find(V.y);
        if(x!=y){
            mark[x] = y;
            sum+=V.w;
        }
    }
    cout<<fixed<<setprecision(2)<<sum<<endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    for(int t=0; t<test; t++){
        cin>>n;
        vector<pair<double, double> >stage;
        mst.clear();
        double x, y;
        for(int i=0; i<n; i++){
            cin>>x>>y;
            stage.push_back(make_pair(x, y));
        }
        if(t) puts("");
        data now;
        for(int i=0; i<n; i++){
            now.x = i;
            for(int j=i+1; j<n; j++){
                now.y = j;
                now.w = pitha(stage[i].first, stage[j].first, stage[i].second, stage[j].second);
                mst.push_back(now);
            }
        }
        MST();
    }
    return 0;
}
