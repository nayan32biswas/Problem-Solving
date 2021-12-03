#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int test, n, k, p, ans;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>n>>k>>p;
        ans = (k+p)%n;
        if(ans==0) ans=n;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
