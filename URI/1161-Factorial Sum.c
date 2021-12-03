#include<stdio.h>
int main()
{
    long long int m,n,sum0=1,sum1=1,sumf,i;
    while(scanf("%lld%lld",&m,&n)!=EOF){
            sumf=0;
        sum0=1;
        for(i=1; i<=m; i++)
            sum0*=i;

        sum1=1;
        for(i=1; i<=n; i++)
            sum1*=i;

        sumf=sum0+sum1;
        printf("%lld\n",sumf);
    }
    return 0;
}
