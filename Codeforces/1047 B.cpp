#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long x, y;
    long long ans = 0;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        ans = max(ans, (x+y));
    }
    cout<<ans<<endl;
    return 0;
}

