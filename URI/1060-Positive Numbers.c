#include<stdio.h>
int main()
{
    float a=6,b,count=0;
    while(a--)
    {
        scanf("%f",&b);
        if(b>0)
            count++;
        else
            continue;
    }
    printf("%.0f valores positivos\n",count);
}
