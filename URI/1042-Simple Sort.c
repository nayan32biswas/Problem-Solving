#include<stdio.h>
int main()
{
    int a,b,c,d,i,j,k,temp;
    scanf("%d%d%d",&a,&b,&c);
    i=a;
    j=b;
    k=c;

    if(i<j)
    {
        temp=i;
        i=j;
        j=temp;
    }
    if(j<k)
    {
        temp=j;
        j=k;
        k=temp;
    }
    if(i<j)
    {
        temp=i;
        i=j;
        j=temp;
    }
        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n",k,j,i,a,b,c);
        return  0;
}
