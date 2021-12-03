#include<stdio.h>
int main()
{
    double a,b,c,d,x,y,z;
    scanf("%lf%lf%lf%lf%lf%lf", &a,&b,&x,&c,&d,&y);
    z = (b*x)+(d*y);
    printf("VALOR A PAGAR: R$ %.2lf\n",z);
return 0;
}
