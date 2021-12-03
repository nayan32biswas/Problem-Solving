#include <bits/stdc++.h>
#define LMT 1000009
using namespace std;

unsigned ans[LMT], List[LMT];
unsigned prime[1000];
unsigned pri[(LMT>>6)+5];

#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))

void seive() {
    unsigned i, j, root=ceil(sqrt(LMT)+1);
    for(i=3, Set(1), prime[0]=2; i<root; i+=2)if(!Check(i)){
        for(j=i*i; j<LMT; j+=(i<<1)) Set(j);
    }
    for(prime[0]=2, j=1, i=3; i<1000; i+=2)if(!Check(i)){prime[j++]=i;}
}
inline bool isPrime(int num){
    if(num==2) return 1;
    if(!(num&1)) return 0;
    return !Check(num);
}
inline int factor(int num){
    if(!(num&1)) {num>>=1;return List[num]+1;}
    int i=1;
    while(num>1){
        if(num%prime[i]==0){
            num/=prime[i];
            return List[num]+1;
        }
        else i++;
    }
}
void stor(int num) {
    for(int i=2; i<num; i++){
        if(isPrime(i)) List[i]=1;
        else List[i] = factor(i);
        ans[i] = List[i]+ans[i-1];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    seive();
    stor(1000002);
    int num;
    while(scanf("%d", &num)==1) {
        printf("%u\n", ans[num]);
    }
    return 0;
}
