#include <bits/stdc++.h>
using namespace std;
#define Size 1000
typedef long long int lli;
void solve(){
    lli s, a, b, c, ans=0;
    cin>>s>>a>>b>>c;
    ans = s/c;
    ans += ((ans/a)*b);
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
