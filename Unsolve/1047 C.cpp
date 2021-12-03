#include <bits/stdc++.h>
using namespace std;
#define Size 15000000
unsigned pri[(Size>>6)+5];
vector<int>prime;
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define isp(n)   ((n==2) || (n>1 && (n&1) && !Check(n)))
void seive();
int n;
bool mark[Size];
int Find(vector<int>vec, int num) {
    int gcd = num;
    for(auto it : vec) {
        gcd = __gcd(it, gcd);
        if(gcd==1)
            return 1;
    }
    return gcd;
}

int main() {
    seive();
    //freopen("input.txt", "r", stdin);
    int x, all, Max=0;
    cin>>n;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        if(i)
            all = __gcd(all, x);
        else
            all = x;
        Max = max(Max, x);
        mark[x] = true;
    }
    std::vector<int>::iterator low,up;
    low=std::lower_bound (prime.begin(), prime.end(), all);
    int i=low-prime.begin();
    for(; prime[i]<=all; i++);
    int root = sqrt(Max)+1, coun;
    Max = 0;
    //cout<<prime[i]<<endl;
    for(; prime[i]<=root; i++){
        coun = 0;
        x = prime[i];
        for(int j=x, k=2; j<Size; j = x*k, k++){
            if(mark[j]==true)coun++;
        }
        Max = max(coun, Max);
    }
    int ans = n-Max;
    if(Max==0) puts("-1");
    else cout<<ans<<endl;
    return 0;
}
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


