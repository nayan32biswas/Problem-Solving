#include <bits/stdc++.h>
using namespace std;
long long A, B, x, y, z, ans;
int main()
{
    cin>>A>>B>>x>>y>>z;
    x = (x*2) + y;
    z = (z*3) + y;
    if(A<x) ans += x-A;
    if(B<z) ans += z-B;
    cout<<ans<<endl;
}
