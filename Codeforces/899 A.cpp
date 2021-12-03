#include <bits/stdc++.h>
using namespace std;
int ans, odd, even, n, x;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x&1) odd++;
        else even++;
    }
    ans = min(odd, even);
    odd -= ans;
    if(odd>2) ans += odd/3;
    cout<<ans<<endl;
}
