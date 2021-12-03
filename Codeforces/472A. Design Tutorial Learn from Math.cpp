#include <iostream>
#include <cmath>
#define LMT 1000008
using namespace std;
unsigned pri[(LMT>>6)+3];
#define Set(n) (pri[n>>6]|=(1<<((n>>1)&31)))
#define Check(n) (pri[n>>6]&(1<<((n>>1)&31)))
void sieve() {
    int i, J, root = sqrt(LMT)+1;
    for(i=3; i<root; i+=2) if(!Check(i)) {
        for(J=i*i; J<LMT; J+=(i<<1)) Set(J);
    }
}
int main()
{
    sieve();
    int n, i, ans;
    cin>>n;
    for(i=3; i<=(n>>1); i++) {
        if(!(i&1) || Check(i)){
            ans = n - i;
            if(!(ans&1) || Check(ans)){
                cout<<i<<' '<<ans<<endl;
                return 0;
            }
        }
    }
}
