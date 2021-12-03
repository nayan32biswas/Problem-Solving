#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 900
using namespace std;
bool pri[N];
int prime[5000];
void seive()
{
    int root=sqrt(N)+1;
    pri[1]=1;
    for(int i=4; i<=N; i+=2){
        pri[i]=1;
    }
    for(int i=3; i<root; i+=2)if(!pri[i]){
        for(int j=i*i; j<=N; j+=i+i)
            pri[j]=1;
    }
    prime[0]=2;
    for(int i=3, j=1; i<=N; i+=2)
        if(!pri[i]){
            prime[j++]=i;
        }
}
int main()
{
    seive();
    int n, mult, ans=0, temp, use[50], i, j, k;
    cin>>n;
    for(i=5; i<=n; i++){
        if(pri[i]==0)
            continue;
        mult=i;
        j = 0, k = 0;
        memset(use,0,sizeof(use));
        while(mult!=0){
            if(mult%prime[j]==0){
                mult/=prime[j];
                continue;
            }
            if(pri[mult]==0 || mult<2) break;
            //cout<<mult<<" "<<k<<' '<<j<<endl;
            prime[j++];
            if(mult%prime[j]==0){
                use[k++]++;
            }
        }
        for(j=0, temp=0; j<50; j++){
            if(use[j]>0){
                temp++;
                cout<<temp<<" "<<j<<endl;
            }
        }
        if(temp==1) ans++;
    }
    cout<<endl<<ans<<endl;
    return 0;
}
