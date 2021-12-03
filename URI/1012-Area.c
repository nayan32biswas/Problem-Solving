#include<stdio.h>
int main()
{
    double a,b,c,pi=3.14159,p,q,r,s,t;

    scanf("%lf%lf%lf",&a,&b,&c);

    p=(a*c)/2;
    q=pi*c*c;
    r=((a+b)*c)/2;
    s=b*b;
    t=a*b;

    printf("TRIANGULO: %.3lf\n",p);
    printf("CIRCULO: %.3lf\n",q);
    printf("TRAPEZIO: %.3lf\n",r);
    printf("QUADRADO: %.3lf\n",s);
    printf("RETANGULO: %.3lf\n",t);
return 0;
}
