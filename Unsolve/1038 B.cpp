#include <bits/stdc++.h>
using namespace std;
long long SUM(long long n) {
    return (n*(n+1))/2;
}

#define Size 45000+100
unsigned pri[(Size>>6)+5];
vector<int>prime;
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
    for(j=0, i=3; i<Size; i+=2)
        if(!Check(i)) {
            prime.push_back(i);
        }
    //printf("Number of prime = %d\ntotal time = %d\n\n", j, clock()-start);
}
bool isDiv(long long x, long long sum) {
    if(sum%x==0)
        return true;
    return false;
}
void show(long long x, int n) {
    //cout<<sum-x<<endl;
    puts("Yes");
    cout<<x<<endl;

    for(int i=1; i<=n; i++) {
        printf("%d ", i);
    }
    puts("");
}
void solve(int n) {
    if(n==1 || n==2) {
        puts("No");
        return;
    }
    int len = prime.size();
    long long sum = SUM(n);
    for(int i=0; prime[i]<n; i++) {
        if(isDiv(prime[i], sum)) {
            show(prime[i], n);
            //if(prime[i]>100)cout<<prime[i]<<endl;
            return;
        }
    }
    //cout<<n<<endl;
}
int main() {
    seive();
    int n;
    cin>>n;
    solve(n);

    //for(int i=3; i<=n; i++)solve(i);
    return 0;

}
