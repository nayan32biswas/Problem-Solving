#include <bits/stdc++.h>
using namespace std;
#define Size 1000009
int pri[Size>>4];
int prime[Size>>3], check[Size];
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define isp(n)   ((n==2) || (n>1 && (n&1) && !Check(n)))
void seive() {
    int i, j, root = ceil(sqrt(Size))+1;
    for(i=3; i<root; i+=2)if(!Check(i)) for(j=i*i; j<Size; j+=(i<<1)) Set(j);
    prime[0]=2;
    for(i=3, j=1; i<Size; i+=2) if(isp(i)) prime[j++] = i;
}
int Find(int r) {
    if(check[r]==r) return r;
    return check[r] = Find(check[r]);
}
int arr[Size];
set<int>SET;

void prime_div(int num) {
    if(isp(num)) return;
    int Fixed = num, x, y;
    for(int i=0, n=2; n*n<=num; i++, n = prime[i]) {
        if(num%n==0) {
            while(num>0 && num%n==0) num/=n;
            x = Find(n);
            y = Find(Fixed);
            if(x!=y) check[x] = y;

        }
    }
    if(num>1) {
        x = Find(num);
        y = Find(Fixed);
        if(x!=y) check[x] = y;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    seive();
    int test, N, ans;
    cin>>test;
    for(int t=1; t<=test; t++) {
        scanf("%d", &N);
        ans = 0;
        SET.clear();
        for(int i=0; i<Size; i++) check[i] = i;
        for(int i=0; i<N; i++){
            scanf("%d", &arr[i]);
            if(arr[i]==1)N--, i--, ans++;
        }
        for(int i=0; i<N; i++)prime_div(arr[i]);
        for(int i=0; i<N; i++)SET.insert(Find(arr[i]));
        ans+=SET.size();
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
