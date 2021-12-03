#include <bits/stdc++.h>
#define N 10011
using namespace std;
bool prime[N];
void seive()
{
    int i, j, root=sqrt(N)+1;
    for(i=3; i<=root; i+=2)if(!prime[i]){
        for(j=i*i; j<=N; j+=i+i)
            prime[j]=1;
    }

}
int main()
{
    //freopen("Input.txt", "r", stdin);
    seive();
    int test, lo, hi, i, ans;
    bool ck;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d", &lo, &hi);
        if(hi<lo) swap(lo, hi);
        if(hi<2){
            printf("-1\n");
            continue;
        }
        else if(hi==2){
            printf("2\n");
            continue;
        }
        else{
            ck=false, ans=0;
            if((hi&1)==0)hi--;
            for(i=hi; i>=lo; i-=2){
                if(prime[i]==0){
                    ans=i;
                    ck=true;
                    break;
                }
            }
            if(ck==true) printf("%d\n", ans);
            else printf("-1\n");
        }
    }
    return 0;
}
