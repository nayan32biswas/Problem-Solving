#include <bits/stdc++.h>
#define SIZ 46400
using namespace std;
int prime[SIZ+5];
bool pri[SIZ+5];
struct data {
    int coun, prim;
};
void seive() {
    int i, J, root=sqrt(SIZ)+2;
    for(pri[1]=1, i=3; i<root; i+=2) if(!pri[i]) {
        for(J=i*i; J<SIZ; J+=(i*2))
            pri[J]=1;
    }
    for(prime[0]=2, i=3, J=1; i<SIZ; i+=2){
        if(pri[i]==0) prime[J++]=i;
    }
}

inline int power(int n, int p) {
    int res=0;
    for(long long po=p; po<=n; po*=p){
        res += n/po;
    }
    return res;
}

bool fact_mod(int n, int num) {

    if(n>=num) return true;

    int root=(int)sqrt(num)+2, p, k, i, cou;
    data store[100];

    for(i=0, k=0; prime[i]<root && prime[i]<=num; i++) {
        if(num%prime[i]==0){
            p = prime[i], cou=0;
            while(num%p==0) {
                cou++;
                num/=p;
            }
            store[k].coun = cou;
            store[k++].prim = p;
        }
    }
    if(num>1) {
        if(num>n) return false;
        store[k].coun = 1;
        store[k++].prim = num;
    }
    for(i=0; i<k; i++) {
        if(store[i].coun - power(n, store[i].prim)>0)
            return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    seive();
    int n, m, num;
    while(scanf("%d%d", &n, &m)==2) {
        if(fact_mod(n, m)) printf("%d divides %d!\n", m, n);
        else printf("%d does not divide %d!\n", m, n);
    }
    return 0;
}
