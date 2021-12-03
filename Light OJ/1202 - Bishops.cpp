#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test, r1, c1, r2, c2;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("Case %d: ", t);
        if(r1==r2 && c1==c2) puts("0");
        else if(abs(r1-r2) == abs(c1-c2)) puts("1");
        else if(((r1&1)==(c1&1)) && ((r2&1)==(c2&1))) puts("2");
        else if(!((r1&1)==(c1&1)) && !((r2&1)==(c2&1))) puts("2");
        else puts("impossible");
    }
}
