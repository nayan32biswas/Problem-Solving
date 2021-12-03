#include <iostream>
#include <cstdio>
#include <cmath>
#define LMT 10070
using namespace std;
int prime[1250];
bool pri[LMT+5];
void seive() {
    int i, J, root=(int)(sqrt(LMT)+2);
    for(i=3; i<root; i+=2)if(!pri[i]) {
        for(J=i*i; J<LMT; J+=(i<<1)) pri[J]=1;
    }
    for(prime[0]=2, i=3, J=1; i<LMT; i+=2)if(!pri[i]) {
        prime[J++]=i;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    seive();
    int num, i, J, sum, pos, ans;
    while(scanf("%d", &num)==1 && num) {
        ans = 0; sum = 0;
        for(i=0, J=0; prime[i]<=num; i++){
            sum+=prime[i];
            while(sum>num) {
                sum-=prime[J++];
            }
            if(sum==num)ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
