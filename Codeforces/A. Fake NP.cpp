#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, dis;
    cin>>l>>r;
    if(l==r) return printf("%d", r), 0;
    dis = abs(l-r);
    if(dis>10) return puts("2"), 0;
    if(r>l) swap(l, r);
    int ans2=0, ans3=0, i;
    for(i=r; i<=l; i++) if(i%2==0) ans2++;
    for(i=r; i<=l; i++) if(i%3==0) ans3++;
    if(ans3>=ans2) puts("3");
    else puts("2");
}

