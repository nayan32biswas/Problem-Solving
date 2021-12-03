#include<stdio.h>
int main()
{
    int x,sum=0,i,a=0,b=1;
    scanf("%d",&x);
    for(i=1; i<=x; i++){
            if(i>1 && i<=x)
                printf(" ");
        printf("%d",a);
        sum=a+b;
        a=b;
        b=sum;
        if(i==x)
            printf("\n");
    }
    return 0;
}
