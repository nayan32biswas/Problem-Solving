#include<stdio.h>
int main()
{
    float a=6,b,count=0,sum=0;
    while(a--)
    {
        scanf("%f",&b);
        if(b>0)
            count++;
            if(b>0)
                sum+=b;
    }
    sum=sum/count;
    printf("%.0f valores positivos\n%.1f\n",count,sum);
}
