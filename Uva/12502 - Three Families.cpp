#include <iostream>
using namespace std;
int main()
{
    int test, ans, a, b, x, y, z;
    cin>>test;
    while(test--){
        cin>>x>>y>>z;
        a=(x*z)<<1;
        b = (y*z);
        ans = (a-b)/(x+y);
        cout<<ans<<endl;
    }
    return 0;
}
