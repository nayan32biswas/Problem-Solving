#include<stdio.h>
int main()
{
    double a,b,c,d,e,n,sum;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

    sum=((a*2)+(b*3)+(c*4)+(d*1))/10;

    if(sum>=7.0) printf("Media: %.1lf\nAluno aprovado.\n",sum);

    else if(sum<=4.9) printf("Media: %.1lf\nAluno reprovado.\n",sum);

    else
    {
        if(sum>=5.0 || sum<=6.9)
        scanf("%lf",&e);
        n=(sum+e)/2;
        printf("Media: %.1lf\nAluno em exame.\n",sum);
        printf("Nota do exame: %.1lf\n",e);
        printf("Aluno aprovado.\nMedia final: %.1lf\n",n);
    }
    return 0;
}
