#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0, x, y, z, t;
    cin>>n>>x>>y>>z;
    t = min(x, y);
    z = min(x, min(y, z));

    n--;
    bool ck = true;
    while(n>0){
        if(ck){
            ans+=t;
            ck = false;
            n--;
        }
        else{
            n--;
            ans+=z;
        }
    }
    cout<<ans<<endl;
}
