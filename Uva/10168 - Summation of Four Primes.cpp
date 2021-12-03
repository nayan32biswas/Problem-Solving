#include <iostream>
#include <cmath>
#include <cstdio>
#define LMT 10000000
using namespace std;
bool pri[LMT+5];
int prime[666666], num;
void seive()
{
    int j, i, root = sqrt(LMT)+2;
    for(i=3; i<root; i+=2)if(!pri[i]){
        for(j=i*i; j<LMT; j+=(i<<1))
            pri[j]=1;
    }
    for(i=3, j=1, prime[0]=2; i<LMT; i+=2)if(!pri[i]){
        prime[j++]=i;
    }
}

int main()
{
    seive();
    int ans, i;
    while(scanf("%d", &num)==1){
        if(num<8){
            puts("Impossible.");
        }
        else {
            if(num&1){
                printf("2 3");
                num-=5;
            }
            else{
                printf("2 2");
                num-=4;
            }
            for(i=0;; i++) {
                ans = num-prime[i];
                if(ans==2 || (ans&1 && !pri[ans])){
                    break;
                }
            }
            printf(" %d %d\n", prime[i], ans);
        }
    }
    return 0;
}

