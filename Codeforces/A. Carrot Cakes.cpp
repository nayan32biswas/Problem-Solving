#include <iostream>
using namespace std;
int main()
{
    double n, t, k, d, x, y;
    cin>>n>>t>>k>>d;
    x = (t*n)/k;
    y = x-d;
    if(y-t>0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
