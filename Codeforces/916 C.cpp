#include <bits/stdc++.h>
using namespace std;
#define Size 200005
int pri[(Size>>5)], prime[(Size/5)];
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define isP(n) ((n==2) || ((n>1) && (n&1) && !Check(n)))
int n, m, last, spa;
void seive(){
    for(int i=3; i*i<=Size; i+=2)if(!Check(n)){
        for(int j=i*i; j<Size; j+=(i<<1)) Set(j);
    }
}
int main()
{
    seive();
    cin>>n>>m;
    spa = n-1;
    for(last=spa+1; !isP(last); last++);
    last = last-spa;
    printf("2 %d\n", spa+last);
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++, m--){
            if(!m) return 0;
            printf("%d %d ", i, j);
            if(i==1){
                if(j==n-1) printf("%d\n", last);
                else if(j==n) puts("2");
                else puts("1");
            }
            else puts("1000000000");
        }
    }
}
