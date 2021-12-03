#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    long long x, x1, y, y1, lo, hi, height, ans;
    while(scanf("%lld%lld%lld%lld", &x, &y, &x1, &y1) && x && y && x1 && y1){
        if(x==x1) ans = abs(y-y1);
        else{
            if(x<x1) swap(x, x1), swap(y, y1);
            height = abs(x-x1);
            lo = y-height, hi = y+height;
            ans = height<<1;
            if(height==1) ans = abs(y-y1)+1;
            else if((y1>lo && y1<hi) && (y&1) != (y1&1)) ans--;
            else ans += min(abs(lo-y1), abs(hi-y1));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
