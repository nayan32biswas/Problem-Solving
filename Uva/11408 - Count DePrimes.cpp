#include <bits/stdc++.h>
#define LMT 5000050
using namespace std;
unsigned prime[LMT], pri[(LMT>>6)+5], store[LMT+9];

#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))

void seive(){
    int i, j, root = ceil(sqrt(LMT))+1;
    for(Set(1), i=3; i<root; i+=2)if(!Check(i)){
        for(j=i*i; j<LMT; j+=i<<1) Set(j);
    }prime[0]=2;
    for(i=3, j=1; i<LMT; i+=2)if(!Check(i))prime[j++]=i;
}

inline bool isPrime(int n) {
    if(n==2) return true;
    if(n<2) return false;
    if(!(n&1)) return false;
    return !Check(n);
}

inline bool sum_prime_fact(int num){
    if(isPrime(num)) return true;
    //if(!(num&1)) return false;
    int sum=0, temp=2, i=0;
    while(temp*temp<=num){
        if(num%temp==0){
            while(num%temp==0){
                num/=temp;
            }
            sum+=temp;
        }
        temp = prime[++i];
    }
    if(num>1) sum+=num;
    return isPrime(sum);
}
void DePrime(){
    int i, num;
    for(i=2, num=0; i<LMT; i++){
        if(sum_prime_fact(i)==true) num++;
        store[i]=num;
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    seive();
    DePrime();
    int a, b;
    while(scanf("%d", &a)!=EOF && a){
        scanf("%d", &b);
        printf("%d\n", (store[b]-store[a-1]));
    }

    return 0;
}
