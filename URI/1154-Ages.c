#include<stdio.h>
int main()
{
    float x,sum=0,c=1,n;
    for(;;){
        scanf("%f",&x);
        if(x<0)
            break;
        else
            sum+=x;
            c++;
    }
    n=sum/(c-1);
    printf("%.2f",n);
}
