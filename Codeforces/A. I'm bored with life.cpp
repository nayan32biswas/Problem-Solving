#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long ans=1, a, b;
    cin>>a>>b;
    for(int i=1; i<=min(a, b); i++) ans*=i;
    cout<<ans<<endl;
}
