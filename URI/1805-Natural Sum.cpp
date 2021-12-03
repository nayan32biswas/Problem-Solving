#include<stdio.h>
int main()
{
    unsigned long long int i;
    double a,b;
    scanf("%lf%lf",&a,&b);
    i=(b-a)*((a+b)/2)+((a+b)/2);
    printf("%lli\n",i);
    return 0;
}
