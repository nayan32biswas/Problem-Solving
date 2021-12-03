#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, l, r, x0=0, y0=0, x1=0, y1=0, ans=0, ans1=0;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d%d",&l, &r);
        if(l==0) x0++;
        else x1++;
        if(r==0) y0++;
        else y1++;
    }
    x0=min(x0, x1);
    y0=min(y0, y1);
    ans=x0+y0;
    cout<<ans<<endl;
    return 0;
}
