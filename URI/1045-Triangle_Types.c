#include<stdio.h>
int main()
{
    double A,B,C,a,b,c,TEMP;
    scanf("%lf%lf%lf",&A,&B,&C);
    if(A<B)
    {
        TEMP=A;
        A=B;
        B=TEMP;
    }
    if(B<C)
    {
        TEMP=B;
        B=C;
        C=TEMP;
    }
     if(A<B)
    {
        TEMP=A;
        A=B;
        B=TEMP;
    }
    a=A*A;
    b=B*B;
    c=C*C;

    if(A>=B+C) printf("NAO FORMA TRIANGULO\n");
      else if(a==b+c) printf("TRIANGULO RETANGULO\n");
        else if(a>b+c) printf("TRIANGULO OBTUSANGULO\n");
            else if(a<b+c) printf("TRIANGULO ACUTANGULO\n");

    if(A==B && B==C) printf("TRIANGULO EQUILATERO\n");
    else if(A==B || B==C) printf("TRIANGULO ISOSCELES\n");
    return 0;
}
