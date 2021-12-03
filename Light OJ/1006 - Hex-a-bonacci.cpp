#include <iostream>
#include <cstdio>
#include <cstring>
#define ull unsigned long long
using namespace std;
ull x[1000000];
ull a, b, c, d, e, g;
ull f(int n ) {
    if(x[n]>0) return x[n]%10000007;
    if( n == 0 ) return a%10000007;
    else if( n == 1 ) return b%10000007;
    else if( n == 2 ) return c%10000007;
    else if( n == 3 ) return d%10000007;
    else if( n == 4 ) return e%10000007;
    else if( n == 5 ) return g%10000007;
    return  x[n]=(f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6));
}
int main() {
    //freopen("input.txt","r",stdin);
    int n, test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%lld %lld %lld %lld %lld %lld %d", &a, &b, &c, &d, &e, &g, &n);
        printf("Case %d: %lld\n", t, f(n)%10000007);
        memset(x,0,sizeof(x));
    }
    return 0;
}
