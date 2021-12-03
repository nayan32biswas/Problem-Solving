#include<iostream>
#include<iomanip>
#include<cstdio>
#include<math.h>
using namespace std;
long double allfib[1000000];
long double fibo(int n);
int main()
{
    int n,test,k;
    long double x,total;
    long long M;
    scanf("%d",&test);
    for(int i=1; i<=test; i++){
        scanf("%d%d%lld",&n,&k,&M);
        x = fibo(n+1);
        total = pow(k,x);
        total =fmod(total,M);
        cout<<fixed<<setprecision(0)<<total<<endl;
    }
    return 0;
}
long double fibo(int n)
{
    if(n<=1)
        return 1;
    if(allfib[n]>0)
        return allfib[n];
    long double x = fibo(n-1)+fibo(n-2);
    allfib[n]=x;
    return x;
}

