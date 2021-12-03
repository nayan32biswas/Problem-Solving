#include<stdio.h>
int main()
{
    int a=5,b,count=0;
    while(a--)
    {
        scanf("%d",&b);
        if(b%2==0)
            count++;
        else
            continue;
    }
    printf("%d valores pares\n",count);
    return 0;
}
