#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, bi, i, x, temp, ans;
    cin>>n>>x;
    for(i=2; i<=n; i++) {
        scanf("%d", &bi);
        if((x<0 && bi<0) || (x>0 && bi>0)) {
            ans = (x+bi);
        }
        else{
            ans = abs(abs(bi)-abs(x));
            if(bi<0 && (abs(bi)>abs(x)))printf("-");
            if(x<0 && (abs(bi)<abs(x)))printf("-");
        }
        printf("%d ", ans);
        if(i==n) return printf("%d\n", bi), 0;
        x = bi;
    }
}
