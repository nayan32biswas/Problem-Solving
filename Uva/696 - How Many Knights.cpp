#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, ans;
    while(cin>>n>>m && n && m){
        int x = n, y = m;
        if(m<n) swap(n, m);
        if(n==1) ans = m;
        else if(n==2) ans = (m/4)*4 + min(m%4, 2)*2;
        else ans = (((m+1)>>1) * ((n+1)>>1)) + ((m>>1) * (n>>1));
        printf("%d knights may be placed on a %d row %d column board.\n", ans, x, y);
    }
    return 0;
}
