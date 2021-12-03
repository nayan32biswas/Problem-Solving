#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int c, i, j, x, y, ans;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            cin>>c;
            if(c==1){x=i, y=j;}
        }
    }
    x<2 ? x=2-x : x=x-2;
    y<2 ? y=2-y : y=y-2;
    ans = x+y;
    cout<<ans<<endl;
    return 0;
}
