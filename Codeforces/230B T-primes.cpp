#include <bits/stdc++.h>
#define N 4000000
using namespace std;
bool prime[N+5];
long long x[1000100];
void seive()
{
    int i, j, root = sqrt(N)+1;
    for(i=3; i<=root; i+=2){
        if(prime[i]==0){
            for(j=i*i; j<=N; j+=i+i)
                prime[j]=1;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    seive();
    long long n, temp;
    cin>>n;
    for(int i=0; i<n; i++)
        scanf("%lld",&x[i]);

    for(int i=0; i<n; i++){
        if(x[i]==4){
            printf("YES\n");
            continue;
        }
        temp = sqrt(x[i]);
        if(temp*temp==x[i] && prime[temp]==0 && temp%2==1 && temp>1)
            printf("YES\n");

        else printf("NO\n");
    }
    return 0;
}
