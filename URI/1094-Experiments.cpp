#include<stdio.h>
int main()
{
    int sumall=0,sum=0,sum1=0,sum2=0,a,n;
    float x,y,z;
    char ch;
    scanf("%d",&n);
    while(n--){
        scanf("%d %c",&a,&ch);
        sumall+=a;
        if(ch=='C')
            sum+=a;
        else if(ch=='R')
            sum1+=a;
        else if(ch=='S')
            sum2+=a;
    }
    x=((float)sum*100)/(float)sumall;
    y=((float)sum1*100)/(float)sumall;
    z=((float)sum2*100)/(float)sumall;
    printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\n",sumall,sum,sum1,sum2);
    printf("Percentual de coelhos: %.2f %%\n",x);
    printf("Percentual de ratos: %.2f %%\n",y);
    printf("Percentual de sapos: %.2f %%\n",z);
    return 0;
}
