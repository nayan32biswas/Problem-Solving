#include<stdio.h>
int main()
{
    int i,a,n;
    scanf("%d",&a);
    i=1;
    while(i<=10)
    {
       n=i*a;
       printf("%d x %d = %d\n",i,a,n);
       i++;
    }
    return 0;
}
