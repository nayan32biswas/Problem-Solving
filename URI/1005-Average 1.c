#include<stdio.h>
int main()
{
    double a,b,c;
    scanf("%lf%lf",&a,&b);
    c = ((a*3.5)+(b*7.5))/(3.5+7.5);
    printf("MEDIA = %.5lf\n", c);
    return 0;
}
