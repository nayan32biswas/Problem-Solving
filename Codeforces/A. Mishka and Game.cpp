#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int ans=0, n, x, y;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x>>y;
        if(x==y)continue;
        if(x>y) ans++;
        else ans--;
    }
    if(ans==0) puts("Friendship is magic!^^");
    else if(ans>0) puts("Mishka");
    else puts("Chris");
    return 0;
}
