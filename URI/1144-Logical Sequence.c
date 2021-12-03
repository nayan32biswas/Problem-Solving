#include<stdio.h>
int main()
{
    int n,i,j,sum=1,sum1=1;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        sum=i*i;
        sum1=sum*i;
            printf("%d %d %d\n",i,sum,sum1);
        for(j=i+1; j<=i+1; j++){
            printf("%d %d %d\n",i,sum+1,sum1+1);
        }
    }
    return 0;
}
