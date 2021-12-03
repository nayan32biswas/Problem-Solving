#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int arr[]={9261,8000,6859,5832,4913,4096,3375,2744,2197,1728,1331,1000,729,512,343,216,125,64,27,8,1};
long long dp[10000][22];

long long ways(int n, int pos){
    if(n==0) return 1;
    if(dp[n][pos]!=-1) return dp[n][pos];
    long long ans=0;
    int i, x;
    for(i=pos; i<21; i++){
        x = n-arr[i];
        if(x>=0) {
            ans+=ways(x, i);
        }
    }
    return dp[n][pos]=ans;
}

int main()
{
    int i, n;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &n)==1){
        printf("%lld\n", ways(n, 0));
    }
    return 0;
}
