#include<stdio.h>
int main()
{
    int x,sum=0,i,a=0,b=1;
    scanf("%d",&x);
    for(i=1; i<=x; i++){
        printf("%d ",a);
        sum=a+b;
        a=b;
        b=sum;
    }
    printf("\n");
    return 0;
}
