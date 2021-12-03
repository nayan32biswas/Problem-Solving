#include <bits/stdc++.h>
#define Size 1000000
using namespace std;
typedef unsigned long long int ull;
unsigned pri[(Size>>6)+5], last;
vector<unsigned>prime(Size/5);
#define p(n) cout<<"    "<<n<<endl
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define isp(n)   ((n==2) || (n>1 && (n&1) && !Check(n)))
void seive();
void factor(ull n) {
    if(n<Size && isp(n)) {
        p(n);
        return;
    }
    for(int i=0, x = prime[i]; i<last && (x*x)<=n; i++, x=prime[i]){
        while(n%x==0){
            p(x);
            n/=x;
        }
    }
    if(n>1)p(n);
}
int main() {
    seive();
    long long int n;
    while(cin>>n && n>0){
        factor(n);
        puts("");
    }
}
void seive() {
    int start = clock();
    unsigned i, j;
    for(i=3; i*i<=Size; i+=2)
        if(!Check(i)) {
            for(j=i*i; j<Size; j+=(i<<1))
                Set(j);
        }
    prime[0] = 2;
    for(j=1, i=3; i<Size; i+=2)
        if(!Check(i)) {
            prime[j++]=i;
        }
    last = j;
    //printf("last prime number is = %d\nNumber of prime = %d\ntotal time = %d\n\n", prime[j-1], j, clock()-start);
}
