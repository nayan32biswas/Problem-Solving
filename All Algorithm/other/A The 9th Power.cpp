#include <iostream>
#include <cstdio>
using namespace std;
int Bigmod(int pow) {
    int res=1, bas=9, mod=10;
    while(pow>0){
        if(pow&1) res=(res*bas)%mod;
        bas = (bas*bas)%mod;
        pow>>=1;
    }
    return res;
}
int main()
{
    int test, n;
    cin>>test;
    while(test--){
        scanf("%d", &n);
        printf("%d\n", Bigmod(n));
    }
    return 0;
}
