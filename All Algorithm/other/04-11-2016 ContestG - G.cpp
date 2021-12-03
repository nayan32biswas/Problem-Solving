#include <bits/stdc++.h>
using namespace std;
long long row(long long x) {
    long long i=0, j=0, coun=0;
    if(x%4==0) return x/4;
    while(j<x){
            j+=4;
            if(j>=x) break;
            coun++;
    }
    j=1;
    while(j<x){
            j+=4;
            if(j>x) break;
            coun++;
    }
    j=x;
    while(j>0){
        j-=4;
        if(j<0) break;
        coun++;
    }
    return coun;
}
int main()
{
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
        long long x, y, res_x, res_y, ans;
        cin>>x>>y;
        res_x = row(x);
        res_y = row(y);
        x--,y--;
        ans = (res_x*y)+(res_y*x);
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
