#include<stdio.h>
int main()
{
    int n,i,sum=1,sum1=1;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        sum=i*i;
        sum1=i*i*i;
        printf("%d %d %d\n",i,sum,sum1);
    }
}
