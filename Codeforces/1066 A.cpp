#include <stdio.h>
#include <math.h>
int rangeDiv(double vi, int li, int ri){
    int lo = ceil(li/vi)*vi;
    int hi = floor(ri/vi)*vi;
    if(lo>hi) return 0;
    return ((hi+lo)/vi);
}
int Li, vi, li, ri;
int solve(){
    scanf("%d%d%d%d", &Li, &vi, &li, &ri);
    return (Li/vi)-rangeDiv(vi, li, ri);
}
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        printf("%d\n", solve());
    }
    return 0;
}
