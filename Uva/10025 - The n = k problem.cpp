#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define SUM(N) ((N*(N+1))>>1)
lli solve(lli key){
    if(key==0) return 3;
    lli start = 0, End = min(key, 50000LL), mid, num;
    while(start < End){
        mid = (start+End)>>1;
        num = SUM(mid);
        if(num<key){
            start = mid+1;
        }
        else if(num>key){
            End = mid-1;
        }
        else break;
    }
    mid = max(mid-2, 0LL);
    do{
        mid++;
        num = SUM(mid);
    }while(num<key || ( (key&1) != (num&1)));
    return mid;
}
int main(){
    //freopen("input.txt", "r", stdin);
    lli N;
    int test;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        scanf("%lld", &N);
        if(t) puts("");
        printf("%lld\n", solve(abs(N)));
    }
    return 0;
}
