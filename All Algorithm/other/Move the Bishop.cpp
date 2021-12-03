#include <bits/stdc++.h>
using namespace std;
int r1, r2, c1, c2;
int main()
{
    cin>>r1>>c1>>r2>>c2;
    if(r1==r2 && c1==c2) return puts("0"), 0;
    if(abs(r1-r2)==abs(c1-c2)) puts("1");
    else if((r1&1)==(c1&1) == (r2&1)==(c2&1)) puts("2");
    else puts("-1");
    return 0;
}
