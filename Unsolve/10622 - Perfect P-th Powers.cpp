#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#define root 46340
#define MAX 2147483648
#define pos 46085
#define p(x) cout<<x<<endl;
using namespace std;
bool reck[root+5], ck;
vector<long long>dp[35];
long long dp0[65536];
bool binary(long long num)
{
    int start=0, mid, End=46085;//46085 is last value position.
    while(start<=End){
		mid = (start+End)/2;
		if(dp0[mid] == num) return true;
		else if(dp0[mid]<num) start = mid+1;
		else if(dp0[mid]>num) End = mid-1;
	}return false;
}
void ff()
{
    int i, J, k;
    long long power;
    for(i=2, k=0; i<=root; i++){
        if(reck[i]==1)continue;
        power=i*i;
        dp0[k++]=power;
        if(power<=root)reck[power]=1;
        power*=i;
        J=0;
        while(power<=MAX){
            if(power<=root)reck[power]=1;
            dp[J].push_back(power);
            power*=i;
            J++;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    ff();
    long long num, num1;
    int i, J, len;
    while(scanf("%lld", &num)!=EOF && num){
        num1 = num;
        if(num<0) num*=-1;
        if(binary(num)==true){
            if(num1<0) puts("1");
            else puts("2");
            continue;
        }
        len=dp[0].size();
        for(i=0, ck=false; len>0; len=dp[++i].size()){
            for(J=0; J<len; J++){
                if(dp[i][J]==num){
                    ck=true;
                    break;
                }
                if(dp[i][J]>num)break;
            }
            if(ck==true)break;
        }
        i+=3;
        if(num1<0 && !(i&1)) i=1;
        if(ck==false)puts("1");
        else printf("%d\n", i);
    }
    return 0;
}
