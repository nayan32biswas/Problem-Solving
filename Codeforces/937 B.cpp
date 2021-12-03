#include <bits/stdc++.h>
using namespace std;
unsigned pri[(10000000>>6)+5];
vector<long long>prime(10000000/5);
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define isp(n)   ((n==2) || (n>1 && (n&1) && !Check(n)))
void seive(int Size) {
    int start = clock();
    unsigned i, j;
    Size = min(Size, 10000000);
    for(i=3; i*i<=Size; i+=2)if(!Check(i)){
        for(j=i*i; j<Size; j+=(i<<1)) Set(j);
    }
    prime[0] = 2;
    for(j=1, i=3; i<Size; i+=2)if(!Check(i)){prime[j++]=i;}
}
int p, y, Size;
bool is_true(int n){
    if(n<Size){
        return isp(n);
    }
    for(int i=0; prime[i]<=Size && (prime[i]*prime[i])<=n; i++){
        if(n%prime[i]==0) return false;
    }
    return true;
}
int main()
{
    cin>>p>>y;
    Size = p;
    seive(y);
    for(int i=y; i>p; i--) {
        if(is_true(i)){
            cout<<i<<endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}

