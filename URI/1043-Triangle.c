#include <stdio.h>
int main()
{
    double a,b,c,x,y;
    scanf ("%lf%lf%lf",&a,&b,&c);
    if(a<b+c&&b<a+c&&c<a+b)
        printf("Perimetro = %.1lf\n",a+b+c);
     else
    {
        y=((a+b)*c)/2;
        printf("Area = %.1lf\n",y);
    }
    return 0;
}

