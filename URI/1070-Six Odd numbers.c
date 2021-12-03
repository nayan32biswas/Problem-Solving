#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    i=n;
    while(i<=n+12)
    {
        if(i%2==1) printf("%d\n",i);
        i++;
    }
    return 0;
}
