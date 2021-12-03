#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    long long sq, n, x, y, num, lo, hi, mid;
    int test, i;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%lld", &n);
        printf("Case %d: ", t);
        if(n==1) puts("1 1");
        else {
            sq = ceil(sqrt(n));
            x = sq, y = sq;
            mid = ((((sq-1)*(sq-1))+1)+(sq*sq))>>1;
            num = abs(mid-n);
            if(sq&1){
                if(n>mid) x -= num;
                else y -= num;
            }
            else {
                if(n>mid) y -= num;
                else x -= num;
            }
            printf("%lld %lld\n", x, y);
        }
    }
    return 0;
}
