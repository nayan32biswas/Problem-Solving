#include <bits/stdc++.h>
using namespace std;
#define Size 1000900
vector<int>prime;
int pri[(Size>>6)+5];
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define isp(n)   ((n==2) || (n>1 && (n&1) && !Check(n)))
void seive() {
    int start = clock();
    unsigned i, j;
    for(i=3; i*i<=Size; i+=2)
        if(!Check(i)) {
            for(j=i*i; j<Size; j+=(i<<1))
                Set(j);
        }
    prime.push_back(2);
    for(i=3, j=1; i<Size; i+=2)
        if(!Check(i)) {
            prime.push_back(i);
        }
    printf("Number of prime = %d\ntotal time = %d\n\n", j, clock()-start);
}
int lower(int n){
    return int(lower_bound(prime.begin(), prime.end(), n)-prime.begin());
}
int upper(int n){
    return int(upper_bound(prime.begin(), prime.end(), n)-prime.begin());
}
int parfect(int x, int n){
    if(n%x==0) return n;
    return (n/x)*x;
}
int main() {
    seive();
    int n;
    cin>>n;
    while(true){

    }
    return 0;
}
