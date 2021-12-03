#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;
void solve()
{
    int s, x;
    cin >> s>>x;
    int ans=1;
    while(s>=x){
        s/=x;
        ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    solve();
    return 0;
}