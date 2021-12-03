#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, ans=0;
    cin>>n>>a>>b;
    for(int i=1; i<n; i++)ans = max(ans, min(a/i, b/(n-i)));
    cout<<ans<<endl;
}
