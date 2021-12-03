#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int arr[]={50, 25, 10, 5, 1}, num;
int dp[8000][5];
int call(int n, int j){
    if(n==0) return 1;
    int ans=0, i;
    if(dp[n][j]!=-1) return dp[n][j];
    for(i=j; i<5; i++){
        if(n-arr[i]>=0)
            ans+=call(n-arr[i], i);
    }
    return dp[n][j]=ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &num)==1){
        printf("%d\n", call(num, 0));
    }
    return 0;
}
