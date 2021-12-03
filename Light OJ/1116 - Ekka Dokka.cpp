#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    long long w, m;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%lld", &w);
        printf("Case %d: ", t);
        if(w&1) puts("Impossible");
        else{
            for(long long i=2; i<99999999999999999; i<<=1)if(w%i==0) m = i;
            printf("%lld %lld\n", w/m, m);
        }
    }
    return 0;
}
