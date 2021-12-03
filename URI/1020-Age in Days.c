#include<stdio.h>
int main()
{
    int a,b,c,n;
    scanf("%d",&n);
    a=n/365;
    b=(n%(365))/30;
    c=(n%(365))%30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",a,b,c);
return 0;
}
