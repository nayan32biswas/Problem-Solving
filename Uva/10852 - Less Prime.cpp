#include <iostream>
#include <cstdio>
#include <cmath>
#define LMT 10000
using namespace std;
bool pri[LMT+5];
void seive() {
    int i, J, root=(int)(sqrt(LMT)+2);
    for(i=3; i<root; i+=2)if(!pri[i]) {
        for(J=i*i; J<LMT; J+=(i<<1)) pri[J]=1;
    }
}
int main()
{
    seive();
    int test, n, x;
    cin>>test;
    for(int t=0; t<test; t++) {
        scanf("%d", &n);
        x = n>>1;
        x++;
        if(!(x&1)) x++;
        for(; x<n; x+=2){
            if(!pri[x]) break;
        }
        cout<<x<<endl;
    }
    return 0;
}
