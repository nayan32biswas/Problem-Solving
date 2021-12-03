#include <iostream>
#include <cmath>
#define N 9000
using namespace std;
bool pri[N], visit[N];
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
        if(!pri[i])
            prime[j++]=i;
}
int main()
{
    seive();
    int n, mult, temp, ans=0, root;
    double x;
    cin>>n;
    root=sqrt(n)+5;
    for(int i=0; i<n; i++){
        for(int j=prime[i]; j<=n; j++){
            if(pri[j]==0)
                continue;
            if(j%prime[i]==0){
                temp = j/prime[i];
                if(pri[temp]==0 && temp>prime[i]){
                    ans++;
                    //cout<<prime[i]<<"   "<<temp<<"   "<<j<<endl;
                }
                else{
                    x=sqrt(temp);
                    if(fmod(x,1)==0){
                        cout<<x<<"  "<<j<<endl;
                        temp=x;
                        if(pri[temp]==0 && temp!=prime[i]){
                            ans++;
                            cout<<prime[i]<<"   "<<temp<<"   "<<j<<endl;
                        }
                    }
                }
            }

        }
    }
    cout<<endl<<ans<<endl;
    return 0;
}
