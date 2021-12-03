#include <iostream>
using namespace std;
int main()
{
    int x, ans;
    cin>>x;
    ans = x/5;
    x=x%5;
    if(x>0) ans++;
    cout<<ans<<endl;
    return 0;
}
