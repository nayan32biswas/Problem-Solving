#include<stdio.h>
int main()
{
    int a,n,i,j,count=0,count1=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a);
            if(a>=10 && a<=20)
                count++;
            else
                count1++;
    }
    printf("%d in\n%d out\n",count,count1);
    return 0;
}
