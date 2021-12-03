#include <bits/stdc++.h>
using namespace std;
int n, pos, l, r, ans;
#define p(a) return cout<<(a)<<endl, 0
int main()
{
    scanf("%d%d%d%d", &n, &pos, &l, &r);
    if(l==1 && r==n) p(0);
    if(l==1 && pos>r) p(1+pos-r);
    if(r==n && pos<l) p(1+l-pos);
    if(l==1) p(r-pos+1);
    if(r==n) p(pos-l+1);
    if(pos>=l && pos<=r) ans += min(pos-l, r-pos)+(r-l);
    else{
        ans = r-l;
        pos>r ? ans += pos-r : ans += l-pos;
    }
    p(ans+2);
    return 0;
}
