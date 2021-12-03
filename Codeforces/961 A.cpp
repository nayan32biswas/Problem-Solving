#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=10000, n, m;
    cin>>n>>m;
    vector<int>M(n);
    while(m--){
        cin>>n;
        M[--n]++;
    }
    for(auto it : M)ans = min(ans, it);
    cout<<ans<<endl;
    return 0;
}
