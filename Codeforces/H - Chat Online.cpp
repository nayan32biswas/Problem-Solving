#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>  ppi;
int p, q;
bool segment[10009];
ppi second1[60];
bool check(int incr){
    int i, j, x, y;
    for(i=0; i<q; i++){
        x = (second1[i].first)+incr;
        y = (second1[i].second)+incr;
        for(; x<=y; x++) if(segment[x]==true) return true;
    }
    return false;
}
int main()
{
    //freopen("input.txt", "r",stdin);
    int i, j, l, r, ans, x, y;
    scanf("%d%d%d%d", &p, &q, &l, &r);
    for(i=0; i<p; i++){
        scanf("%d%d", &x, &y);
        for(; x<=y; x++) segment[x]=true;
    }
    for(i=0; i<q; i++){
        scanf("%d%d", &x, &y);
        second1[i] = make_pair(x, y);
    }
    for(i=l, ans=0; i<=r; i++) if(check(i)) ans++;

    cout<<ans<<endl;
    return 0;
}

