#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, a;
    cin>>l>>r>>a;
    int ans = min(l, r);
    l = max(l-ans, r-ans);
    ans *= 2;
    l = min(a, l);
    a -= l;
    ans += l*2;
    if(a&1) a--;
    if(a>0) ans+=a;
    cout<<ans<<endl;
    return 0;
}
