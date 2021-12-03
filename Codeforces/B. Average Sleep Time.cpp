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
int a[200009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, div, i, hi, lo;
    read(n);
    read(k);
    div = (n-k)+1;
    for(i=0; i<n; i++) read(a[i]);
    double ans, sum=0;

    for(hi=0; hi<k; hi++) sum+=a[hi];
    ans = sum/div;
    for(lo=0; hi<n; hi++, lo++){
        sum-=a[lo];
        sum+=a[hi];
        ans+=(sum/div);
    }
    cout<<fixed<<setprecision(7)<<ans<<endl;
    return 0;
}
