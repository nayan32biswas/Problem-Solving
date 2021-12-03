#include<stdio.h>
int main()
{
    unsigned long long int a,b,c,k;
    int j,count,n;
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&k);
        a=0; b=1; count=0;
        for(j=1; j<=k; j++){
            c=a+b;
            a=b;
            b=c;
        }
        printf("Fib(%lld) = %lld\n",k,a);
    }
    return 0;
}
