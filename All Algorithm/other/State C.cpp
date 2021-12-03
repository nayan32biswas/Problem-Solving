#include <bits/stdc++.h>
#define SIZ 10000009
using namespace std;
int prime[SIZ], ans[120];
bool pri[SIZ];
void seave()
{
    int i, J, root=sqrt(SIZ)+2;
    for(pri[1]=1, i=3; i<root; i+=2)if(!pri[i]){
        for(J=i*i; J<SIZ; J+=(i<<1)) pri[J]=1;
    }prime[2]=1;
    for(i=3, J=1; i<SIZ; i++){
        if((i&1) && !(pri[i])) J++;
        prime[i]=J;
    }
    J=9387856, i=0;
    while(J>0){
        J  -= (prime[J]+1);
        ans[i++]=J;
    }
    reverse(ans, ans+i);
}
int main()
{
    seave();
    int i, J, n, test;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d", &n);
        if(n<1) i=1;
        else{
            for(i=0; i<111; i++)
                if(ans[i]>n) break;
        }
        printf("Case %d: %d\n", t, i-1);

    }
    return 0;
}
