#include <iostream>
using namespace std;
int main()
{
    int k, n, w, ans;
    cin>>k>>w>>n;
    ans = (k*((n*(n+1))/2))-w;
    if(ans<0) ans = 0;
    cout<<ans<<endl;
    return 0;
}
