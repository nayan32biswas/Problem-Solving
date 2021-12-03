#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
int arr[]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long dp[31000][12];

long long way(int n, int pos){
    if(n==0) return 1;
    if(dp[n][pos]!=-1) return dp[n][pos];
    long long ans=0;
    int i, x;
    for(i=pos; i<11; i++){
        x = n-arr[i];
        if(x>=0){
            ans+=way(x, i);
        }
    }
    return dp[n][pos]=ans;
}

int to_int(char *s, int len){
    int i, n=0;
    for(i=0; i<len; i++)if(s[i]!='.'){
        n=((n*10)+(s[i]-'0'));
    }
    return n;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    long long n, len;
    char num[10];
    memset(dp, -1, sizeof(dp));
    while(scanf("%s", num)==1){
        len = strlen(num);
        n = to_int(num, len);
        if(n==0) return 0;
        if(len==4) printf("  ");
        else if(len==5) printf(" ");
        n = way(n, 0);
        printf("%s%17lld\n", num, n);
        //cout<<fixed<<setprecision(6)<<num<<setw(17)<<n<<endl;
    }
    return 0;
}
