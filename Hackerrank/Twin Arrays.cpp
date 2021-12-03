#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x){
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}
pair<int, int>a, b, c, d;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, ans;
    a.first = b.first = (1<<30);
    a.second = b.second = 0;
    read(n);
    for(int i=0; i<n; i++){
        read(x);
        if(a.first>=x){
            b.first = a.first;
            b.second = a.second;
            a.first = x;
            a.second = i;
        }
    }
    c.first = d.first = (1<<30);
    c.second = d.second = 0;
    for(int i=0; i<n; i++){
        read(x);
        if(c.first>=x){
            d.first = c.first;
            d.second = c.second;
            c.first = x;
            c.second = i;
        }
    }
    //cout<<a.first<<' '<<b.first<<' '<<c.first<<' '<<d.first<<endl;
    ans = 1<<30;
    if(a.second!=c.second) ans = a.first+c.first;
    if(a.second!=d.second) ans = min(ans, a.first+d.first);
    if(b.second!=c.second) ans = min(ans, b.first+c.first);
    if(b.second!=d.second) ans = min(ans, b.first+d.first);
    cout<<ans<<endl;
    return 0;
}
