#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans, l, w, h, x, n;
    while(scanf("%d", &n) && n){
        ans = x = 0;
        while(n--){
            scanf("%d%d%d", &l, &w, &h);
            if(h>x) ans = l*w*h, x=h;
            else if(h==x)ans = max(ans, l*w*h);
        }
        printf("%d\n", ans);
    }
    return 0;
}

