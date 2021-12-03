#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
unsigned long long a=2, b=6, dp[1000100];
int main()
{
    int i, test, n;
    dp[0]=0, dp[1]=2;
    for(i=2; i<1000010; i++){
        a = a+b;
        dp[i]=a;
        b+=4;
    }
    cin>>test;
    for(i=0; i<test; i++){
        scanf("%d", &n);
        printf("%lld\n", dp[n-1]);
    }
    return 0;
}
