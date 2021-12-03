#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, k, l, c, d, p, nl, np, Min;
    int x, y, z;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    x=((k*l)/nl)/n;
    y=(c*d)/n;
    z=(p/np)/n;
    x=min(x,y);
    x=min(x,z);
    cout<<x<<endl;
    return 0;
}
